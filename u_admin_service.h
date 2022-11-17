#pragma once
#ifndef admin_service_h
#define admin_service_h

#include "u_user_service.h"
#include "connection.h"

class admin_service : public user_service {
public:
	void get_all_users();
	void _update(int id);
	void _delete(int id);
};
#endif