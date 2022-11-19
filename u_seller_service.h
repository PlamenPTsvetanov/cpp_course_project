#pragma once
#ifndef seller_service_h
#define seller_service_h
#include "u_user_service.h"
#include "connection.h"
#include "u_seller.h"
class seller_service : public user_service {
	seller_c* seller;
public:
	seller_service();
	void _create();
	void _update();
	void _delete();
};
#endif