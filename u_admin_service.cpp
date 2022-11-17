#include "u_admin_service.h"

void admin_service::get_all_users() {
    connection* con = new connection();
    int user_count = -1;

    try {
        con->init();
        int idx = 1;
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT COUNT(*) FROM USERS");

        pstmt->execute();
        ResultSet* rs = pstmt->getResultSet();
        while (rs->next()) {
            user_count = rs->getInt(1);
        }
        cout << "Users are " << user_count << endl;

        delete rs;
        delete pstmt;

        pstmt = con->get_connection()->prepareStatement("SELECT * FROM USERS");

        pstmt->execute();
        rs = pstmt->getResultSet();
        while (rs->next()) {
            cout << rs->getInt(1) << " | " << rs->getString(2) << " | " << rs->getString(3) << " | " << rs->getString(4) << " | " << rs->getString(5) << " | " << rs->getString(6) << " | " << rs->getString(7) << endl;
        }

        delete rs;
        delete pstmt;
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Error message: " << e.what() << endl;
    }
    delete con;
}

void admin_service::_delete(int id) {
    int type = -1;
    bool flag = user_exists(id);
    connection* con = new connection();
    try {
        con->init();
        if (flag)
        {
            PreparedStatement* pstmt = con->get_connection()->prepareStatement("DELETE FROM BUYERS WHERE USER_ID = ?");
            pstmt->setInt(1, id);
            pstmt->execute();
            cout << "Connection from buyers removed!" << endl;
            delete pstmt;

            pstmt = con->get_connection()->prepareStatement("DELETE FROM SELLERS WHERE USER_ID = ?");
            pstmt->setInt(1, id);
            pstmt->execute();
            cout << "Connection from sellers removed" << endl;
            delete pstmt;

            pstmt = con->get_connection()->prepareStatement("DELETE FROM USERS WHERE ID = ?");
            pstmt->setInt(1, id);
            pstmt->execute();
            cout << "User deleted" << endl;
            delete pstmt;
        }
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Deletion unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
}

void admin_service::_update(int id) {
    bool flag = user_exists(id);
    connection* con = new connection();
    try {
        con->init();
        if (flag)
        {
            user_service::_update(id);

            cout << "Enter your comment: " << endl;
            cin >> ws;
            string admin_remark;
            getline(cin, admin_remark);

            PreparedStatement* pstmt = con->get_connection()->prepareStatement("UPDATE USERS SET ADMIN_REMARK = ? WHERE ID = ?");
            pstmt->setString(1, admin_remark);
            pstmt->setInt(2, id);
            pstmt->execute();
            cout << "User updated";
            delete pstmt;
        }
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Update unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
} 