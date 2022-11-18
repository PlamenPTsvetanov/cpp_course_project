#pragma once
#ifndef storefront_h
#define storefront_h

#include "c_common.h"

class storefront_c {
	int seller_id;
	vector<int> ad_ids;
	bool is_boosted;
	
public:
	int get_seller_id();
	vector<int>* get_ad_ids();
	bool get_is_boosted();

	void set_seller_id(int id);
	void set_ad_ids(vector<int>* ids);
	void set_is_boosted(bool is_boosted);
};
#endif