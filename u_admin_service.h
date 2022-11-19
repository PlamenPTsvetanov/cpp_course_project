#pragma once
#ifndef admin_service_h
#define admin_service_h

#include "u_user_service.h"
#include "v_vehicle_service.h"
#include "connection.h"

class admin_service : public user_service, public vehicle_service {
public:
	void get_all_users();
	void get_all_vehicles();
	void _update(int id, string table);
	void _delete(int id, string table);
};
#endif