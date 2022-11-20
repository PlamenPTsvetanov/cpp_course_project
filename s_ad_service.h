#pragma once
#ifndef s_ad_service_h
#define s_ad_service_h

#include "connection.h"
#include "s_ad.h"
#include "u_user_service.h"
#include "u_buyer.h"

class ad_service {
private:
	ad_c* ad;
	
public:
	ad_service();
	void _create(int user_id, int vehicle_id, string v_type);
	void _update(int ad_id);
	void _delete(int ad_id);
	void load_user_ads(int user_id);
	void sell(int ad_id, buyer_c* buyer);
};

#endif