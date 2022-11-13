#include "connection.h"

void connection::init()
{
	set_driver();
	set_connection();
}

PreparedStatement* connection::set_prepared_statement(string statement) {
	return con->prepareStatement(statement);
	
}

Connection* connection::get_connection() {
	return con;
}


void connection::set_driver() {
	try
	{
		driver = get_driver_instance();
	}
	catch (sql::SQLException e)
	{
		cout << "Could not set driver. Error message: " << e.what() << endl;
		exit(1);
	}
}

void connection::set_connection() {
	try
	{
		con = driver->connect(server, username, password);
		con->setSchema(schema);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not establish connection. Error message: " << e.what() << endl;
		exit(1);
	}
}

void connection::end() {
	if (con != NULL)
	{
		delete con;
	}
}