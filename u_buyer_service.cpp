#include "u_buyer_service.h"
#include "connection.h"

buyer_service::buyer_service() {
    buyer = new buyer_c();
}

void buyer_service::_create() {
	user_c* base_user = user_service::_create();
    buyer->inherit(base_user);

    double amount;
    cout << "Enter wallet amount:" << endl;
    cin >> amount;
    buyer->set_wallet(amount);

    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO BUYERS VALUES(?, ?, ?, ?, ?, ?, ?);");
        pstmt->setInt(idx++, 0);
        pstmt->setString(idx++, buyer->get_name());
        pstmt->setString(idx++, buyer->get_family());
        pstmt->setString(idx++, buyer->get_username());
        pstmt->setString(idx++, buyer->get_password());
        pstmt->setDouble(idx++, buyer->get_wallet());
        pstmt->setString(idx, "No remarks");

        pstmt->execute();
        cout << "Buyer profile with username: " << user->get_username() <<  " successfully created!" << endl;

        delete pstmt;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
}

void buyer_service::_update(int id) {
    double amount;
    cout << "Enter new wallet amount:" << endl;
    cin >> amount;
    buyer->set_wallet(amount);

    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        PreparedStatement* update = con->get_connection()->prepareStatement("UPDATE BUYERS SET wallet = ? WHERE ID = ?");
        update->setDouble(idx++, buyer->get_wallet());
        update->setInt(idx, id);

        update->execute();
        cout << "Buyer " << user->get_username() << " now has wallet amount -> " << amount << endl;

        delete update;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
}

void buyer_service::_delete(int id) {
    __super::_delete(id, "BUYERS");

    cout << "Deleted buyer with id: " << id << endl;
}

buyer_c* buyer_service::get_one(int id) {
    connection* con = new connection();
    try {
        con->init();
        PreparedStatement* update = con->get_connection()->prepareStatement("SELECT * FROM BUYERS WHERE ID = ?");
        update->setInt(1, id);

        update->execute();

        ResultSet* rs = update->getResultSet();

        while (rs->next()) {
            buyer->set_id(rs->getInt(1));
            buyer->set_name(rs->getString(2));
            buyer->set_family(rs->getString(3));
            buyer->set_username(rs->getString(4));
            buyer->set_password(rs->getString(5));
            buyer->set_wallet(rs->getDouble(6));
        }
        delete update;
        delete rs;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
    return buyer;
}