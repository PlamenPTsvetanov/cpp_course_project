#include "v_vehicle_service.h"

vehicle_service::vehicle_service() {
	this->vehicle = new vehicle_c();
}

vehicle_c* vehicle_service::_create() {

	int year_of_construction, horse_power;
	string type, brand, model;

	cout << "Enter brand of vehicle:" << endl;
	cin >> ws;
	getline(cin, brand);
	vehicle->set_brand(brand);

	cout << "Enter model of vehicle:" << endl;
	cin >> ws;
	getline(cin, model);
	vehicle->set_model(model);

	cout << "Enter year of construction of vehicle:" << endl;
	cin >> year_of_construction;
	vehicle->set_year(year_of_construction);

	cout << "Enter horse power of vehicle:" << endl;
	cin >> horse_power;
	vehicle->set_horse_power(horse_power);

	return vehicle;
	
}

vehicle_c* vehicle_service::_update(int id) {

	int year_of_construction, horse_power;
	string type, brand, model;

	cout << "Update brand of vehicle:" << endl;
	cin >> brand;
	vehicle->set_brand(brand);

	cout << "Update model of vehicle:" << endl;
	cin >> model;
	vehicle->set_model(model);

	cout << "Update year of construction of vehicle:" << endl;
	cin >> year_of_construction;
	vehicle->set_year(year_of_construction);

	cout << "Update horse power of vehicle:" << endl;
	cin >> horse_power;
	vehicle->set_horse_power(horse_power);
	
	return vehicle;
}

vehicle_c* vehicle_service::_delete(int id, string table)  {
	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("DELETE FROM " + table + " WHERE ID = ?");
		pstmt->setInt(idx++, id);

		pstmt->execute();

		delete pstmt;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Deletion unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
}