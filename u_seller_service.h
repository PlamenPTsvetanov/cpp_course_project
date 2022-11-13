#pragma once
#ifndef seller_service_h
#define seller_service_h
#include "u_user_service.h"
#include "connection.h"
class seller_service : public user_service {
public:
	void _create();
	void _update(int id);
};
#endif