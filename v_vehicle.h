#pragma once
#ifndef vehicle_h
#define vehicle_h

#include "c_common.h"
class vehicle_c {
private:
	int id, year_of_construction, horse_power;
	string type, brand, model;
public:
	int get_id();

	string get_brand();

	string get_model();

	int get_year();

	int get_horse_power();

	void set_id(int id);

	void set_brand(string brand);

	void set_model(string model);

	void set_year(int year);

	void set_horse_power(int horse_power);
	
	void inherit(vehicle_c* parent);

	void print_data();
};
#endif