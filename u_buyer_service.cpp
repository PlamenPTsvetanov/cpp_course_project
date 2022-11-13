#include "u_buyer_service.h"
#include "connection.h"

void buyer_service::_create() {
	user_service::_create();
    user->set_id(user_service::get_id());

    double amount;
    cout << "Enter wallet amount:" << endl;
    cin >> amount;

    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        cout << "ID is : " <<  user->get_id() << endl;
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO BUYERS VALUES(?, ?, ?)");
        pstmt->setInt(idx++, 0);
        pstmt->setInt(idx++, user->get_id());
        pstmt->setDouble(idx, amount);

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