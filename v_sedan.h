#pragma once
#ifndef sedan_h
#define sedan_h

#include "c_common.h"
#include "v_vehicle.h"

class sedan_c : public vehicle_c {
	int previous_owners;
	bool is_all_wheel_drive;
public:

	int get_previous_owners();

	bool get_is_all_wheel_drive();

	void set_previous_owners(int owners);

	void set_is_all_wheel_drive(bool all_wheel_drive);

	void inherit(vehicle_c* parent);
};


#endif