#include "u_admin_service.h"

void admin_service::get_all_users() {
    connection* con = new connection();
    int user_count = -1;

    try {
        con->init();
      
        PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT * FROM BUYERS");

        pstmt->execute();
        ResultSet* rs = pstmt->getResultSet();
        while (rs->next()) {
            cout << "\t|\t" << "BUYER" << "\t|\t" << rs->getInt(1) << "\t|\t" << rs->getString(2) << "\t|\t" << rs->getString(3) << "\t|\t" << rs->getString(4) << "\t|\t" << rs->getString(5) << "\t|" << endl;
        }

        delete rs;
        delete pstmt;

        pstmt = con->get_connection()->prepareStatement("SELECT * FROM SELLERS");

        pstmt->execute();
        rs = pstmt->getResultSet();
        while (rs->next()) {
            cout << "\t|\t" << "SELLER" << "\t|\t" << rs->getInt(1) << "\t|\t" << rs->getString(2) << "\t|\t" << rs->getString(3) << "\t|\t" << rs->getString(4) << "\t|\t" << rs->getString(5) << "\t|" << endl;
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

void admin_service::_delete(int id, string table) {
    string message; 
    if (table == "sellers") {
        user_exists(id, table);
        message = "Seller";
    }
    else if (table == "buyers") {
        user_exists(id, table);
        message = "Buyer";
    }
    else if (table == "sedans" || table == "trucks" || table == "motorcycles") {
        vehicle_exists(id, table);
        message = "Vehicle";
    }
    else {
        throw invalid_argument("No table found");
    }

    connection* con = new connection();
    try {
        con->init();
        PreparedStatement* pstmt;

        if (message == "Seller") {
            pstmt = con->get_connection()->prepareStatement("DELETE FROM ADS WHERE SELLER_ID = ?");
            pstmt->setInt(1, id);
            pstmt->execute();
            delete pstmt;
            cout << "Removed seller ads" << endl;
        }

        pstmt = con->get_connection()->prepareStatement("DELETE FROM " + table + " WHERE ID = ?");
        pstmt->setInt(1, id);
        pstmt->execute();
        cout << message <<" removed!" << endl;
        delete pstmt;        
    }
    catch (sql::SQLException e) {
        con->get_connection()->rollback();
        cerr << "Deletion unsuccessful! Error message: " << e.what() << endl;
    }
    delete con;
   
}

void admin_service::_update(int id, string table) {
    if (table == "buyers" || table == "sellers") {
        user_exists(id, table);
        connection* con = new connection();
        try {
            con->init();
            
            user_c* base_user = user_service::_update(id);

            cout << "Enter your comment: " << endl;
            cin >> ws;
            string admin_remark;
            getline(cin, admin_remark);

            int idx = 1;
            PreparedStatement* pstmt = con->get_connection()->prepareStatement("UPDATE " + table + " SET NAME = ?, FAMILY = ?, USERNAME = ?, PASSWORD = ?, ADMIN_REMARKS = ? WHERE ID = ?");
            pstmt->setString(idx++, base_user->get_name());
            pstmt->setString(idx++, base_user->get_family());
            pstmt->setString(idx++, base_user->get_username());
            pstmt->setString(idx++, base_user->get_password());
            pstmt->setString(idx++, admin_remark);
            pstmt->setInt(idx, id);
            pstmt->execute();

            cout << "User updated" << endl;
            delete pstmt;
            
        }
        catch (sql::SQLException e) {
            con->get_connection()->rollback();
            cerr << "Update unsuccessful! Error message: " << e.what() << endl;
        }
        delete con;
    }
    else if (table == "sedans" || table == "trucks" || table == "motorcycles") {
        cout << "Here\n";
        vehicle_exists(id, table);
        connection* con = new connection();
        try {
            con->init();

            vehicle_c* base_vehicle = vehicle_service::_update(id);

            int idx = 1;
            PreparedStatement* pstmt = con->get_connection()->prepareStatement("UPDATE " + table + " SET BRAND = ?, MODEL = ?, YEAR_OF_CONSTRUCTION = ?, HORSE_POWER = ? WHERE ID = ?");
            pstmt->setString(idx++, base_vehicle->get_brand());
            pstmt->setString(idx++, base_vehicle->get_model());
            pstmt->setInt(idx++, base_vehicle->get_year());
            pstmt->setInt(idx++, base_vehicle->get_horse_power());
            pstmt->setInt(idx, id);
            pstmt->execute();

            cout << "Vehicle updated" << endl;
            delete pstmt;

        }
        catch (sql::SQLException e) {
            con->get_connection()->rollback();
            cerr << "Update unsuccessful! Error message: " << e.what() << endl;
        }
        delete con;
    }
    else {
        throw invalid_argument("Table not found");
    }
} 


void admin_service::get_all_vehicles() {
    connection* con = new connection();
    int user_count = -1;

    try {
        con->init();

        PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT * FROM SEDANS");

        pstmt->execute();
        ResultSet* rs = pstmt->getResultSet();
        while (rs->next()) {
            cout << setw(10);
            cout << "\t|\t" << "SEDAN" << "\t|\t" << rs->getInt(1) << "\t|\t" << rs->getString(2) << "\t|\t" << rs->getString(3) << "\t|\t" << rs->getInt(4) << "\t|\t" << rs->getInt(5) << "\t|" << endl;
        }

        delete rs;
        delete pstmt;

        pstmt = con->get_connection()->prepareStatement("SELECT * FROM TRUCKS");

        pstmt->execute();
        rs = pstmt->getResultSet();
        while (rs->next()) {
            cout << "\t|\t" << "TRUCK" << "\t|\t" << rs->getInt(1) << "\t|\t" << rs->getString(2) << "\t|\t" << rs->getString(3) << "\t|\t" << rs->getInt(4) << "\t|\t" << rs->getInt(5) << "\t|" << endl;
        }

        delete rs;
        delete pstmt;

        pstmt = con->get_connection()->prepareStatement("SELECT * FROM MOTORCYCLES");

        pstmt->execute();
        rs = pstmt->getResultSet();
        while (rs->next()) {
            cout << "\t|\t" << "MOTORCYCLE" << "\t|\t" << rs->getInt(1) << "\t|\t" << rs->getString(2) << "\t|\t" << rs->getString(3) << "\t|\t" << rs->getInt(4) << "\t|\t" << rs->getInt(5) << "\t|" << endl;
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