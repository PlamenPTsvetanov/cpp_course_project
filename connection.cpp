#include "connection.h"

void connection::init()
{
	set_driver();
	set_connection();
}

PreparedStatement* connection::set_prepared_statement(string statement) {
	return con->prepareStatement(statement);
	
}

ResultSet* connection::get_result_set() {
	return pstmt->getResultSet();
}

void connection::set_result_set(ResultSet* rs) {
	cout << "";
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

void connection::clear() {
	if (pstmt != NULL)
	{
		delete pstmt;
	}

	if (result != NULL)
	{
		delete result;
	}
}

void connection::end() {
	clear();
	if (con != NULL)
	{
		delete con;
	}
}