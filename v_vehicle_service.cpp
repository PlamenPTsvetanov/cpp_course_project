﻿#include "v_vehicle_service.h"

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


	connection* con = new connection();
	try {
		con->init();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("INSERT INTO VEHICLES VALUES(?, ?, ?, ?, ?, ?)");
		pstmt->setInt(idx++, 0);
		pstmt->setString(idx++, vehicle->get_type());
		pstmt->setString(idx++, vehicle->get_brand());
		pstmt->setString(idx++, vehicle->get_model());
		pstmt->setInt(idx++, vehicle->get_year());
		pstmt->setInt(idx, vehicle->get_horse_power());

		pstmt->execute();
		
		delete pstmt;

		cout << "Creation of car " << vehicle->get_brand() << " " << vehicle->get_model() << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
	
}

void vehicle_service::_update() {

	int id, year_of_construction, horse_power;
	string type, brand, model;

	id = check_vehicle();
	connection* con = new connection();
	try {

		con->init();

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

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("UPDATE VEHICLES SET TYPE = ?, BRAND = ?, MODEL = ?, YEAR_OF_CONSTRUCTION = ?, HORSE_POWER = ? WHERE ID = ?");
		pstmt->setString(idx++, vehicle->get_type());
		pstmt->setString(idx++, vehicle->get_brand());
		pstmt->setString(idx++, vehicle->get_model());
		pstmt->setInt(idx++, vehicle->get_year());
		pstmt->setInt(idx++, vehicle->get_horse_power());
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

void vehicle_service::_delete() {

	string brand, model;
	int id = -1;

	connection* con = new connection();
	try {
		con->init();

		id = check_vehicle();

		int idx = 1;
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("DELETE FROM VEHICLES WHERE ID = ?");
		pstmt->setInt(idx++, id);

		pstmt->execute();

		delete pstmt;
		cout << "Deleted entry!" << endl;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Deletion unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
}

int vehicle_service::check_vehicle() {
	string brand, model;
	int id = -1;

	cout << "Brand of vehicle to update:" << endl;
	cin >> ws;
	getline(cin, brand);

	cout << "Model of vehicle to update:" << endl;
	cin >> ws;
	getline(cin, model);

	connection* con = new connection();
	con->init();

	PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT ID FROM VEHICLES WHERE BRAND = ? AND MODEL = ?");
	pstmt->setString(1, brand);
	pstmt->setString(2, model);

	pstmt->execute();
	ResultSet* rs = pstmt->getResultSet();

	if (rs->next()) {
		id = rs->getInt(1);
	}
	else {
		throw invalid_argument("No vehicle found!");
	}
	delete pstmt;
	delete rs;
	delete con;

	return id;
}