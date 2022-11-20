#include "u_seller_service.h"

seller_service::seller_service() {
    this->seller = new seller_c();
}

void seller_service::_create() {
    user_c* base_user = user_service::_create();
    seller->inherit(base_user);

    string email, telephone, payment_info;
    cout << "Enter email:" << endl;
    cin >> email;
    seller->set_email(email);

    cout << "Enter telephone:" << endl;
    cin >> telephone;
    seller->set_telephone(telephone);

    cout << "Enter further payment information:" << endl;
    getline(cin >> ws, payment_info);
    seller->set_payment_info(payment_info);

    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO SELLERS VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?);");
        pstmt->setInt(idx++, 0);
        pstmt->setString(idx++, seller->get_name());
        pstmt->setString(idx++, seller->get_family());
        pstmt->setString(idx++, seller->get_username());
        pstmt->setString(idx++, seller->get_password());
        pstmt->setString(idx++, seller->get_email());
        pstmt->setString(idx++, seller->get_telephone());
        pstmt->setString(idx++, seller->get_payment_info());
        pstmt->setString(idx, "No remarks");

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

void seller_service::_update(int id) {
    string email, telephone, info;
    cout << "Update email:" << endl;
    cin >> email;
    seller->set_email(email);

    cout << "Update telephone number:" << endl;
    cin >> telephone;
    seller->set_telephone(telephone);

    cout << "Update additional info:" << endl;
    getline(cin >> ws, info);
    seller->set_payment_info(info);

    connection* con = new connection();
    try {
        con->init();
        int idx = 1;
        PreparedStatement* pstmt = con->get_connection()
            ->prepareStatement("UPDATE SELLERS SET email = ?, telephone = ?, additional_info = ?  WHERE ID = ?");
        pstmt->setString(idx++, seller->get_email());
        pstmt->setString(idx++, seller->get_telephone());
        pstmt->setString(idx++, seller->get_payment_info());
        pstmt->setInt(idx, id);

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

void seller_service::_delete(int id) {
    __super::_delete(id, "SELLERS");

    cout << "Deleted seller with id: " << id << endl;
}