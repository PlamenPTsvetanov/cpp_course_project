#pragma once
#ifndef truck_h
#define truck_h

#include "c_common.h"
#include "v_vehicle.h"

class truck_c : public vehicle_c {
	int capacity, weight;
	bool is_special_use;

public: 

	int get_capacity();

	int get_weight();

	bool get_is_special_use();

	void set_capacity(int capacity);

	void set_weight(int weight);

	void set_is_special_use(bool special_use);
};


#endif