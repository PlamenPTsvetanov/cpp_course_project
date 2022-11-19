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

void vehicle_service::_delete(int id, string table)  {
	connection* con = new connection();
	try {
		con->init();

		PreparedStatement* pstmt = con->get_connection()->prepareStatement("DELETE FROM " + table + " WHERE ID = ?");
		pstmt->setInt(1, id);

		pstmt->execute();

		delete pstmt;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Deletion unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
}

vehicle_c* vehicle_service::get_one(int id, string table) {
	connection* con = new connection();
	try {
		con->init();

		PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT * FROM " + table + " WHERE ID = ?");
		pstmt->setInt(1, id);

		pstmt->execute();
		ResultSet* rs = pstmt->getResultSet();
	
		while (rs->next()) {
			vehicle->set_brand(rs->getString(2));
			vehicle->set_model(rs->getString(3));
			vehicle->set_year(rs->getInt(4));
			vehicle->set_horse_power(rs->getInt(5));
		}

		delete rs;
		delete pstmt;
		delete con;

		return vehicle;
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Selection unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
	return NULL;
}

vector<int> vehicle_service::get_many(string table) {
	vector<int> to_ret;
	connection* con = new connection();
	try {
		con->init();

		PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT * FROM " + table);

		pstmt->execute();
		ResultSet* rs = pstmt->getResultSet();

		while (rs->next()) {
			to_ret.push_back(rs->getInt(1));
			vehicle->set_brand(rs->getString(2));
			vehicle->set_model(rs->getString(3));
			vehicle->set_year(rs->getInt(4));
			vehicle->set_horse_power(rs->getInt(5));


			vehicle->print_data();
		}

		delete rs;
		delete pstmt;
		
	}
	catch (sql::SQLException e) {
		con->get_connection()->rollback();
		cerr << "Selection unsuccessful! Error message: " << e.what() << endl;
	}
	delete con;
	return to_ret;
}

void vehicle_service::vehicle_exists(int id, string table) {
	bool flag = false;
	connection* con = new connection();
	try {
		con->init();
		PreparedStatement* pstmt = con->get_connection()->prepareStatement("SELECT ID FROM " + table + " WHERE ID = ?");
		pstmt->setInt(1, id);
		pstmt->execute();
		ResultSet* rs = pstmt->getResultSet();

		flag = rs->next();

		delete rs;
		delete pstmt;
	}
	catch (SQLException e) {
		con->get_connection()->rollback();
		cerr << "Creation unsuccessful! Error message: " << e.what() << endl;
	}
	if (!flag) {
		throw InvalidArgumentException("No user with this ID found!\n");
		system("exit");
	}
	delete con;
}