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

	Connection* get_connection();

private:
	void set_driver();

	void set_connection();
};



#endif 
