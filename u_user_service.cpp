#include "u_user_service.h"
#include "connection.h"


user_service::user_service() {
    user = new user_c();
};

/// <summary>
/// Създава нов потребител
/// </summary>
void user_service::_create()
{
    cout << "Enter your first name:" << endl;
    cin >> in_name;
    cout << "Enter your family name:" << endl;
    cin >> in_family;
    cout << "Enter your username:" << endl;
    cin >> in_username;
    cout << "Enter your password:" << endl;
    cin >> in_password;
    cout << "Do you wish to\n\t1.buy\n\t2.sell" << endl;
    cin >> in_role;

    user->set_name(in_name);
    user->set_family(in_family);
    user->set_username(in_username);
    user->set_password(in_password);
    user->set_role(in_role == 2 ? "seller" : "buyer");

    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO USERS VALUES(?, ?, ?, ?, ?, ?);");
        pstmt->setInt(idx++, 0);
        pstmt->setString(idx++, user->get_name());
        pstmt->setString(idx++, user->get_family());
        pstmt->setString(idx++, user->get_username());
        pstmt->setString(idx++, user->get_password());
        pstmt->setString(idx, user->get_role());

        pstmt->execute();

        delete pstmt;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
    }
   
    delete con;
};

/// <summary>
/// Актуализира данните за потребител
/// Ако се използва от наследник, който не е админ
/// не се очаква идентификатор.
/// Ако се ползва от админ, то той има право да достъпва
/// всички потребители и да ги променя
/// </summary>
/// <param name="id"></param>
void user_service::_update(int id = -1) {
    cout << "Update first name:" << endl;
    cin >> in_name;
    cout << "Update family name:" << endl;
    cin >> in_family;
    cout << "Update username:" << endl;
    cin >> in_username;
    cout << "Update password:" << endl;
    cin >> in_password;

    user->set_name(in_name);
    user->set_family(in_family);
    user->set_username(in_username);
    user->set_password(in_password);

    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        PreparedStatement* update = con->get_connection()->prepareStatement("UPDATE users SET name = ?, family = ?, username = ?, password = ? WHERE ID = ?");
        update->setString(idx++, user->get_name());
        update->setString(idx++, user->get_family());
        update->setString(idx++, user->get_username());
        update->setString(idx++, user->get_password());
        update->setInt(idx, id == -1 ? user->get_id() : id);

        update->executeQuery();

        delete update;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Update unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
}

/// <summary>
/// Логва потребител в системата
/// </summary>
user_c* user_service::_log_in() {
    cout << "Enter your username:" << endl;
    cin >> in_username;
    cout << "Enter your password:" << endl;
    cin >> in_password;

    
    connection* con = new connection();
    int id = -1;
    try {
        
        con->init();

        
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT id, name, family, username, password, role FROM USERS WHERE USERNAME = ?");
        pstmt->setString(1, in_username);
        pstmt->execute();
        
        ResultSet* rs = pstmt->getResultSet();

        while (rs->next()) {
            id = rs->getInt(1);
            user->set_name(rs->getString(2));
            user->set_family(rs->getString(3));
            user->set_username(rs->getString(4));
            user->set_password(rs->getString(5));
            user->set_role(rs->getString(6));
        }
        delete rs;
        delete pstmt;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Error message: " << e.what() << endl;
    }

    if (in_password == user->get_password())
    {
        user->set_id(id);
        cout << "User with id : " << user->get_id() << " logged in!" << endl;
    }
    else {
        throw InvalidArgumentException("Wrong password!\n");
        system("exit");
    }
    delete con;
    return user;
}

/// <summary>
/// Занулява логнатия потребител
/// </summary>
void user_service::_log_out() {
    delete user;
    cout << "Logged out!" << endl;
}

int user_service::get_id() {
    int id = -1;
    connection* con = new connection();
    try { 
        con->init();

        PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT ID FROM USERS WHERE USERNAME = ?");
        pstmt->setString(1, user->get_username());

        pstmt->executeQuery();
        ResultSet* rs = pstmt->getResultSet();
        
        while (rs->next()) {
            id = rs->getInt(1);
        }
        
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Error message: " << e.what() << endl;
    }
    return id;
}