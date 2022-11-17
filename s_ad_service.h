#pragma once
#ifndef s_ad_service_h
#define s_ad_service_h

#include "connection.h"
#include "s_ad.h"
#include "u_user_service.h"

class ad_service {
private:
	ad_c* ad;
	
public:
	ad_service();
	void _create(int user_id, int vehicle_id);
	void _update(int add_id);
	void _delete(int add_id);
	void load_user_ads(int user_id);
};

#endif