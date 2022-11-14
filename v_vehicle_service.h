#pragma once
#ifndef vehicle_service
#define vehicle_service

#include "connection.h"
#include "v_vehicle.h"

class vehicle_service {
	vehicle_c* vehicle;
public:
	void _create();
	void _update();
	void _delete();
};
#endif