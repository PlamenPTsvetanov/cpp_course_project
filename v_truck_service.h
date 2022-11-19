#pragma once
#ifndef truck_service_h
#define truck_service_h

#include "v_vehicle_service.h"
#include "v_truck.h"

class truck_service : public vehicle_service {
	truck_c* truck;
public:
	truck_service();
	void _create();
	void _update(int id);
	void _delete(int id);
	vector<int> get_many();
	vehicle_c* get_one(int id);
};
#endif
