#include "u_seller_service.h"

void seller_service::_create() {
    user_service::_create();
    user->set_id(user_service::get_id());

    string email, telephone, payment_info;
    cout << "Enter email:" << endl;
    cin >> email;
    cout << "Enter telephone:" << endl;
    cin >> telephone;
    cout << "Enter further payment information:" << endl;
    cin >> payment_info;

    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        cout << "ID is : " << user->get_id() << endl;
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO SELLERS VALUES(?, ?, ?, ?, ?)");
        pstmt->setInt(idx++, 0);
        pstmt->setInt(idx++, user->get_id());
        pstmt->setString(idx++, email);
        pstmt->setString(idx++, telephone);
        pstmt->setString(idx, payment_info);

        pstmt->execute();
        cout << "Seller profile with username: " << user->get_username() << " successfully created!" << endl;

        delete pstmt;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
}

void seller_service::_update(int id = -1) {
    user_service::_update(id);

    string email, telephone, info;
    cout << "Update email:" << endl;
    cin >> email;
    cout << "Update telephone number:" << endl;
    cin >> telephone;
    cout << "Update additional info:" << endl;
   
    //removing whitespaces so we can read info
    getline(cin >> ws, info);

    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        PreparedStatement* pstmt = con->get_connection()
            ->prepareStatement("UPDATE SELLERS SET email = ?, telephone = ?, info = ?  WHERE USER_ID = ?");
        pstmt->setString(idx++, email);
        pstmt->setString(idx++, telephone);
        pstmt->setString(idx++, info);
        pstmt->setInt(idx, user->get_id());

        pstmt->execute();
        cout << "Seller " << user->get_username() << " now has email -> " << email 
                                                  << ", telepohne -> " << telephone
                                                  << ", info -> " << info << endl;

        delete pstmt;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
}