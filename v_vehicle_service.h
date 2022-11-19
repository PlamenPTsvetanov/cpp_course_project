#pragma once
#ifndef vehicle_service_h
#define vehicle_service_h

#include "connection.h"
#include "v_vehicle.h"

class vehicle_service {
	vehicle_c* vehicle;
public:
	vehicle_service();
	vehicle_c* _create();
	vehicle_c* _update(int id);

	void _delete(int id, string table);
	vector<int> get_many(string table);
	vehicle_c* get_one(int id, string table);
protected:
	void vehicle_exists(int id, string table);
};
#endif