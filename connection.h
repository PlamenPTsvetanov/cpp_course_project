#pragma once
#ifndef connection_h
#define connection_h

#include "d_database_common.h"
using namespace sql;

class connection { 
	Driver* driver;
	Connection* con;
public:
	void init();

	/// <summary>
	/// Методът едновремено задава стойност на заявката 
	/// и връща стойността и за задаване на стойност на
	/// параметрите ѝ
	/// </summary>
	/// <param name="statement"></param>
	/// <returns>PreparedStatement*</returns>
	PreparedStatement* set_prepared_statement(string statement);

	Connection* get_connection();


	void end();

private:
	void set_driver();

	void set_connection();
};



#endif 
