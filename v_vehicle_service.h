#pragma once
#ifndef vehicle_service_h
#define vehicle_service_h

#include "connection.h"
#include "v_vehicle.h"

class vehicle_service {
	vehicle_c* vehicle;
public:
	vehicle_service();
	void _create();
	void _update();
	void _delete();
private:
	int check_vehicle();
};
#endif