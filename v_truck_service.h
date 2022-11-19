#pragma once
#ifndef truck_service_h
#define truck_service_h

#include "v_vehicle_service.h"

class truck_service : public vehicle_service {
public:
	void _create();
	void _update();
};
#endif
