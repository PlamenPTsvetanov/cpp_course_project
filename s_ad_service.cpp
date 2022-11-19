#include "s_ad_service.h"

ad_service::ad_service() {
	this->ad = new ad_c();
}

void ad_service::_create(int user_id, int vehicle_id, string v_type) {
	double price;
	string title, additional_info;
	ad->set_seller_id(user_id);
	ad->set_vehicle_id(vehicle_id);
	ad->set_vehicle_type(v_type);

	cout << "Enter title of ad:" << endl;
	cin >> ws;
	getline(cin, title);
	ad->set_title(title);

	cout << "Enter price of item:" << endl;
	cin >> price;
	ad->set_price(price);

	cout << "Enter additional info for ad:" << endl;
	cin >> ws;
	getline(cin, additional_info);
	ad->set_additional_info(additional_info);


	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO ADS VALUES(?, ?, ?, ?, ?, ?, ?)");
		pstmt->setInt(idx++, 0);
		pstmt->setInt(idx++, ad->get_seller_id());
		pstmt->setInt(idx++, ad->get_vehicle_id());
		pstmt->setString(idx++, ad->get_vehicle_type());
		pstmt->setString(idx++, ad->get_title());
		pstmt->setDouble(idx++, ad->get_price());
		pstmt->setString(idx, ad->get_additional_info());

		pstmt->execute();

		delete pstmt;
		cout << "Creation of ad with title " << ad->get_title() << " successfull!" << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;

}

void ad_service::_update(int ad_id) {

	double price;
	string title, additional_info;

	cout << "Enter title of ad:" << endl;
	cin >> ws;
	getline(cin, title);
	ad->set_title(title);

	cout << "Enter price of item:" << endl;
	cin >> price;
	ad->set_price(price);

	cout << "Enter additional info for ad:" << endl;
	cin >> ws;
	getline(cin, additional_info);
	ad->set_additional_info(additional_info);

	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("UPDATE ADS SET TITLE = ?, PRICE = ?, ADDITIONAL_INFO = ? WHERE ID = ?");
		pstmt->setString(idx++, ad->get_title());
		pstmt->setDouble(idx++, ad->get_price());
		pstmt->setString(idx++, ad->get_additional_info());
		pstmt->setInt(idx, ad_id);

		pstmt->execute();

		delete pstmt;
		cout << "Update successfull!" << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Update unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;

}

void ad_service::_delete(int add_id) {

	string brand, model;

	connection* con = new connection();
	try {
		con->init();

		PreparedStatement* pstmt = con->get_connection()->prepareStatement("DELETE FROM ADS WHERE ID = ?");
		pstmt->setInt(1, add_id);

		pstmt->execute();

		delete pstmt;
		cout << "Deletion successfull!" << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Deletion unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
}

void ad_service::load_user_ads(int user_id) {
	connection* con = new connection();
	try {
		con->init();

		PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT * FROM ADS WHERE SELLER_ID = ?");
		pstmt->setInt(1, user_id);

		pstmt->execute();
		ResultSet* rs = pstmt->getResultSet();
		while (rs->next()) {
			cout << "|\t" << rs->getInt(1) << "\t|\t" << rs->getInt(3) << "\t|\t" << rs->getString(4) << "\t|\t" << rs->getDouble(5) << "\t|\t" << rs->getString(6) << "\t|\t" << rs->getString(7) << endl;
		}
		delete rs;
		delete pstmt;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Selection unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
}