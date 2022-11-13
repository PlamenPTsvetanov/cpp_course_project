#include "connection.h"
bool flag = true;

void connection::init()
{
	if (flag)
	{
		set_driver();
		set_connection();

	}
	else {
		flag = false;
	}
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
		con->setAutoCommit(true);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not establish connection. Error message: " << e.what() << endl;
		exit(1);
	}
}