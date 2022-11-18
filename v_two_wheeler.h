#pragma once
#ifndef two_wheeler_h
#define two_wheeler_h

#include "c_common.h"
#include "v_vehicle.h"

class two_wheeler_c : public vehicle_c {	
	bool is_track, is_modded;

public:

	bool get_is_track();

	void set_is_track(bool is_track);

	bool get_is_modded();

	void set_is_modded(bool is_modded);
};

#endif