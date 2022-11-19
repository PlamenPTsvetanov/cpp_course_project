#include "v_sedan_service.h"

sedan_service::sedan_service() {
	this->sedan = new sedan_c();
}

void sedan_service::_create() {
	vehicle_c* base_vehicle = __super::_create();
	cout << base_vehicle->get_brand();
	sedan->inherit(base_vehicle);

	int previous_owners;
	string is_all_wheel_drive;

	cout << "Enter number of previous owners of sedan:" << endl;
	cin >> previous_owners;
	sedan->set_previous_owners(previous_owners);

	cout << "Is the sedan all wheel drive(Y/N):" << endl;
	cin >> is_all_wheel_drive;
	sedan->set_is_all_wheel_drive(is_all_wheel_drive == "Y" ? true : false);


	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO SEDANS VALUES(?, ?, ?, ?, ?, ?, ?)");
		pstmt->setInt(idx++, 0);
		pstmt->setString(idx++, sedan->get_brand());
		pstmt->setString(idx++, sedan->get_model());
		pstmt->setInt(idx++, sedan->get_year());
		pstmt->setInt(idx++, sedan->get_horse_power());
		pstmt->setInt(idx++, sedan->get_previous_owners());
		pstmt->setBoolean(idx, sedan->get_is_all_wheel_drive());
		pstmt->execute();

		delete pstmt;

		cout << "Created sedan " << sedan->get_brand() << " " << sedan->get_model() << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
}

void sedan_service::_update(int id) {

	vehicle_c* base_vehicle = __super::_update(id);
	sedan->inherit(base_vehicle);

	int previous_owners;
	string is_all_wheel_drive;

	cout << "Enter number of previous owners of sedan:" << endl;
	cin >> previous_owners;
	sedan->set_previous_owners(previous_owners);

	cout << "Is the sedan all wheel drive(Y/N):" << endl;
	cin >> is_all_wheel_drive;
	sedan->set_is_all_wheel_drive(is_all_wheel_drive == "Y" ? true : false);


	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("UPDATE SEDANS SET BRAND = ?, MODEL = ?, YEAR_OF_CONSTRUCTION = ?, HORSE_POWER = ?, PREVIOUS_OWNERS = ?, IS_ALL_WHEEL_DRIVE = ? WHERE ID = ?");
		pstmt->setString(idx++, sedan->get_brand());
		pstmt->setString(idx++, sedan->get_model());
		pstmt->setInt(idx++, sedan->get_year());
		pstmt->setInt(idx++, sedan->get_horse_power());
		pstmt->setInt(idx++, sedan->get_previous_owners());
		pstmt->setBoolean(idx++, sedan->get_is_all_wheel_drive());
		pstmt->setInt(idx, id);

		pstmt->executeQuery();

		delete pstmt;
		cout << "Updated entry!" << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Update unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;

}

void sedan_service::_delete(int id) {
	__super::_delete(id, "SEDANS");
	cout << "Successfully deleted sedan with id " << id << endl;
}

vector<int> sedan_service::get_many() {
	return __super::get_many("SEDANS");
}

vehicle_c* sedan_service::get_one(int id) {
	return __super::get_one(id, "SEDANS");
}