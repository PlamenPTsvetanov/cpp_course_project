#pragma once
#ifndef motorcycle_service_h
#define motorcycle_service_h

#include "v_vehicle_service.h"
#include "v_motorcycle.h"

class motorcycle_service : public vehicle_service {
	motorcycle_c* tw;
public:
	motorcycle_service();
	void _create();
	void _update(int id);
	void _delete(int id);
	vector<int> get_many();
	vehicle_c* get_one(int id);
};
#endif
