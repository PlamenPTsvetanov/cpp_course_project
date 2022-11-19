#include "u_user_service.h"
#include "connection.h"


user_service::user_service() {
    user = new user_c();
};

/// <summary>
/// Създава нов потребител
/// </summary>
user_c* user_service::_create()
{
    cout << "Enter your first name:" << endl;
    cin >> in_name;
    cout << "Enter your family name:" << endl;
    cin >> in_family;
    cout << "Enter your username:" << endl;
    cin >> in_username;
    cout << "Enter your password:" << endl;
    cin >> in_password;

    user->set_name(in_name);
    user->set_family(in_family);
    user->set_username(in_username);
    user->set_password(in_password);

    return user;
};

/// <summary>
/// Актуализира данните за потребител
/// Ако се използва от наследник, който не е админ
/// не се очаква идентификатор.
/// Ако се ползва от админ, то той има право да достъпва
/// всички потребители и да ги променя
/// </summary>
/// <param name="id"></param>
user_c* user_service::_update(int id = -1) {
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
    return user;
}

void user_service::_delete(int id, string table) {
    user_exists(id, table);
    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("DELETE FROM " + table + " WHERE ID = ?");
        pstmt->setInt(idx, id);

        pstmt->execute();
        delete pstmt;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Deletion unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
}

/// <summary>
/// Логва потребител в системата
/// </summary>
user_c* user_service::_log_in(string table) {
    cout << "Enter your username:" << endl;
    cin >> in_username;
    cout << "Enter your password:" << endl;
    cin >> in_password;

    
    connection* con = new connection();
    int id = -1;
    try {
        
        con->init();

        
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT id, name, family, username, password FROM " + table + " WHERE USERNAME = ? ");
        pstmt->setString(1, in_username);
        pstmt->execute();
        
        ResultSet* rs = pstmt->getResultSet();

        while (rs->next()) {
            id = rs->getInt(1);
            user->set_name(rs->getString(2));
            user->set_family(rs->getString(3));
            user->set_username(rs->getString(4));
            user->set_password(rs->getString(5));
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

int user_service::_logged_in_id() {
    return this->user->get_id();
}

void user_service::user_exists(int id, string table) {
    bool flag = false;
    connection* con = new connection();
    try {
        con->init();
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT ID FROM " + table +" WHERE ID = ?");
        pstmt->setInt(1, id);
        pstmt->execute();
        ResultSet* rs = pstmt->getResultSet();

        flag = rs->next();

        delete rs;
        delete pstmt;
    }
    catch (SQLException e) {
        con->get_connection()->rollback();
        cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
    }
    if (!flag) {
        throw InvalidArgumentException("No user with this ID found!\n");
        system("exit");
    }
    delete con;
}