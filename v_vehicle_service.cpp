#include "v_vehicle_service.h"

vehicle_service::vehicle_service() {
	this->vehicle = new vehicle_c();
}

void vehicle_service::_create() {

	int year_of_construction, horse_power;
	string type, brand, model;

	cout << "Enter type of vehicle:" << endl;
	cin >> type;
	vehicle->set_type(type);

	cout << "Enter brand of vehicle:" << endl;
	cin >> brand;
	vehicle->set_brand(brand);

	cout << "Enter model of vehicle:" << endl;
	cin >> model;
	vehicle->set_model(model);

	cout << "Enter year of construction of vehicle:" << endl;
	cin >> year_of_construction;
	vehicle->set_year(year_of_construction);

	cout << "Enter horse power of vehicle:" << endl;
	cin >> horse_power;
	vehicle->set_horse_power(horse_power);


	connection* con = new connection();
	try {
		con->init();

		int idx = 0;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO VEHICLES VALUES(?, ?, ?, ?, ?, ?)");
		pstmt->setInt(idx++, 0);
		pstmt->setString(idx++, vehicle->get_type());
		pstmt->setString(idx++, vehicle->get_brand());
		pstmt->setString(idx++, vehicle->get_model());
		pstmt->setInt(idx++, vehicle->get_year());
		pstmt->setInt(idx, vehicle->get_horse_power());

		pstmt->execute();

		delete pstmt;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
	
}

void vehicle_service::_update() {

	int year_of_construction, horse_power;
	string type, brand, model;

	connection* con = new connection();
	try {
		con->init();

		check_vehicle();

		cout << "Update type of vehicle:" << endl;
		cin >> type;
		vehicle->set_type(type);

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

		int idx = 0;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO VEHICLES VALUES(?, ?, ?, ?, ?, ?)");
		pstmt->setInt(idx++, 0);
		pstmt->setString(idx++, vehicle->get_type());
		pstmt->setString(idx++, vehicle->get_brand());
		pstmt->setString(idx++, vehicle->get_model());
		pstmt->setInt(idx++, vehicle->get_year());
		pstmt->setInt(idx, vehicle->get_horse_power());

		pstmt->execute();

		delete pstmt;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Update unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;

}

void vehicle_service::_delete() {

	string brand, model;
	int id;

	connection* con = new connection();
	try {
		con->init();

		check_vehicle();

		int idx = 0;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("DELETE FROM VEHICLES WHERE ID = ?");
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

void vehicle_service::check_vehicle() {
	string brand, model;

	cout << "Brand of vehicle to update:" << endl;
	cin >> brand;

	cout << "Model of vehicle to update:" << endl;
	cin >> model;

	connection* con;
	PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT ID FROM VEHICLES WHERE BRAND = ? AND MODEL = ?");
	pstmt->setString(1, brand);
	pstmt->setString(2, model);

	ResultSet* rs = pstmt->getResultSet();
	if (rs->next()) {
		cout << "Vehicle found! ID is : " << rs->getInt(1) << endl;
	}
	else {
		cout << "No such vehicle found!" << endl;
		return;
	}
	delete pstmt;
	delete rs;
}