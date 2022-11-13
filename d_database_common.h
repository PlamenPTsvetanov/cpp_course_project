#pragma once
#ifndef database_common_h
#define database_common_h
#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

using namespace std; 

const string server = "localhost:3306";
const string username = "root";
const string password = "root";
const string schema = "course_project";


#endif