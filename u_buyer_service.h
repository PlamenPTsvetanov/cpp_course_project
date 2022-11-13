#pragma once
#ifndef buyer_service_h
#define buyer_service_h

#include "u_user_service.h"
#include "u_buyer.h"
class buyer_service : public user_service {
	public:
		void _create();
		void _update(int id);
};

#endif // !buyer_service_h
