#pragma once
#ifndef s_ad_h
#define s_ad_h

#include "c_common.h"
class ad_c {
	double price;
	struct date
	{
		int day, month, year;
	} date;
	int id, seller_id, vehicle_id;
	string title, additional_info;


public:
	int get_id();
	int get_seller_id();
	int get_vehicle_id();
	string get_title();
	double get_price();
	string get_date();
	string get_additional_info();

	void set_id(int id);
	void set_seller_id(int seller);
	void set_vehicle_id(int vehicle);
	void set_title(string title);
	void set_price(double price);
	void set_date();
	void set_additional_info(string info);
};

#endif