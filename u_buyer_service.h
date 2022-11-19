#pragma once
#ifndef buyer_service_h
#define buyer_service_h

#include "u_user_service.h"
#include "u_buyer.h"
class buyer_service : public user_service {
	buyer_c* buyer;
	public:
		buyer_service();
		void _create();
		void _update();
		void _delete();
};

#endif // !buyer_service_h
