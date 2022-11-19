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
    buyer->add_to_wallet(amount);

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

void buyer_service::_update() {
    int id = _logged_in_id();

    double amount;
    cout << "Enter new wallet amount:" << endl;
    cin >> amount;
    buyer->add_to_wallet(amount);

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


void buyer_service::_delete() {
    int id = _logged_in_id();
    __super::_delete(id, "BUYERS");

    cout << "Deleted buyer with id: " << id << endl;
}