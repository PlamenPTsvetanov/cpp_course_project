#pragma once
#ifndef sedan_service_h
#define sedan_service_h

#include "v_vehicle_service.h"
#include "v_sedan.h"

class sedan_service : public vehicle_service {
	sedan_c* sedan;
public:
	sedan_service();
	void _create();
	void _update(int id);
	void _delete(int id);
};
#endif
