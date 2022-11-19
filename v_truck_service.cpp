#include "v_truck_service.h"

truck_service::truck_service() {
	this->truck = new truck_c();
}

void truck_service::_create() {
	vehicle_c* base_vehicle = __super::_create();
	cout << base_vehicle->get_brand();
	truck->inherit(base_vehicle);

	int capacity, weight;
	string is_special_use;

	cout << "Enter capacity of truck:" << endl;
	cin >> capacity;
	truck->set_capacity(capacity);

	cout << "Enter weight of truck:" << endl;
	cin >> weight;
	truck->set_weight(weight);

	cout << "Is the truck for special use? (Y/N):" << endl;
	cin >> is_special_use;
	truck->set_is_special_use(is_special_use == "Y" ? true : false);

	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO TRUCKS VALUES(?, ?, ?, ?, ?, ?, ?, ?)");
		pstmt->setInt(idx++, 0);
		pstmt->setString(idx++, truck->get_brand());
		pstmt->setString(idx++, truck->get_model());
		pstmt->setInt(idx++, truck->get_year());
		pstmt->setInt(idx++, truck->get_horse_power());
		pstmt->setInt(idx++, truck->get_capacity());
		pstmt->setInt(idx++, truck->get_weight());
		pstmt->setBoolean(idx, truck->get_is_special_use());
		pstmt->execute();

		delete pstmt;

		cout << "Created truck " << truck->get_brand() << " " << truck->get_model() << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
}

void truck_service::_update(int id) {

	vehicle_c* base_vehicle = __super::_update(id);
	truck->inherit(base_vehicle);

	int capacity, weight;
	string is_special_use;

	cout << "Update capacity of truck:" << endl;
	cin >> capacity;
	truck->set_capacity(capacity);

	cout << "Update weight of truck:" << endl;
	cin >> weight;
	truck->set_weight(weight);

	cout << "Update special use? (Y/N):" << endl;
	cin >> is_special_use;
	truck->set_is_special_use(is_special_use == "Y" ? true : false);


	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("UPDATE TRUCKS SET BRAND = ?, MODEL = ?, YEAR_OF_CONSTRUCTION = ?, HORSE_POWER = ?, CAPACITY = ?, WEIGHT = ?, IS_SPECIAL_USE = ? WHERE ID = ?");
		pstmt->setString(idx++, truck->get_brand());
		pstmt->setString(idx++, truck->get_model());
		pstmt->setInt(idx++, truck->get_year());
		pstmt->setInt(idx++, truck->get_horse_power());
		pstmt->setInt(idx++, truck->get_capacity());
		pstmt->setInt(idx++, truck->get_weight());
		pstmt->setBoolean(idx++, truck->get_is_special_use());
		pstmt->setInt(idx, id);

		pstmt->executeQuery();

		delete pstmt;
		cout << "Updated truck!" << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Update unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;

}

void truck_service::_delete(int id) {
	__super::_delete(id, "TRUCKS");
	cout << "Successfully deleted truck with id " << id << endl;
}

vector<int> truck_service::get_many() {
	return __super::get_many("TRUCKS");
}

vehicle_c* truck_service::get_one(int id) {
	return __super::get_one(id, "TRUCKS");
}