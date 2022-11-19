#include "v_motorcycle_service.h"

motorcycle_service::motorcycle_service() {
	this->tw = new motorcycle_c();
}

void motorcycle_service::_create() {
	vehicle_c* base_vehicle = __super::_create();
	
	tw->inherit(base_vehicle);

	char is_track, is_modded;

	cout << "Is motorcycle track suited? (Y/N)" << endl;
	cin >> is_track;
	tw->set_is_track(is_track == 'Y');

	cout << "Is motorcycle modded? (Y/N)" << endl;
	cin >> is_modded;
	tw->set_is_modded(is_modded == 'Y');

	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO MOTORCYCLES VALUES(?, ?, ?, ?, ?, ?, ?)");
		pstmt->setInt(idx++, 0);
		pstmt->setString(idx++, tw->get_brand());
		pstmt->setString(idx++, tw->get_model());
		pstmt->setInt(idx++, tw->get_year());
		pstmt->setInt(idx++, tw->get_horse_power());
		pstmt->setBoolean(idx++, tw->get_is_track());
		pstmt->setBoolean(idx, tw->get_is_modded());
		pstmt->execute();

		delete pstmt;

		cout << "Created motorcycle " << tw->get_brand() << " " << tw->get_model() << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
}

void motorcycle_service::_update(int id) {

	vehicle_c* base_vehicle = __super::_update(id);
	tw->inherit(base_vehicle);

	int capacity, weight;
	string is_special_use;

	char is_track, is_modded;

	cout << "Update is motorcycle track suited? (Y/N)" << endl;
	cin >> is_track;
	tw->set_is_track(is_track == 'Y');

	cout << "Update is motorcycle modded? (Y/N)" << endl;
	cin >> is_modded;
	tw->set_is_modded(is_modded == 'Y');


	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("UPDATE MOTORCYCLES SET BRAND = ?, MODEL = ?, YEAR_OF_CONSTRUCTION = ?, HORSE_POWER = ?, IS_TRACK = ?, IS_MODDED = ? WHERE ID = ?");
		pstmt->setString(idx++, tw->get_brand());
		pstmt->setString(idx++, tw->get_model());
		pstmt->setInt(idx++, tw->get_year());
		pstmt->setInt(idx++, tw->get_horse_power());
		pstmt->setBoolean(idx++, tw->get_is_track());
		pstmt->setBoolean(idx++, tw->get_is_modded());
		pstmt->setInt(idx, id);

		pstmt->executeQuery();

		delete pstmt;
		cout << "Updated motorcycle!" << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Update unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;

}

void motorcycle_service::_delete(int id) {
	__super::_delete(id, "MOTORCYCLES");
	cout << "Successfully deleted motorcycle with id " << id << endl;
}