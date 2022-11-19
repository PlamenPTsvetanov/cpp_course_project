#include "v_sedan.h"

int sedan_c::get_previous_owners() {
	return this->previous_owners;
}

bool sedan_c::get_is_all_wheel_drive() {
	return this->is_all_wheel_drive;
}

void sedan_c::set_previous_owners(int owners) {
	this->previous_owners = owners;
}


void sedan_c::set_is_all_wheel_drive(bool all_wheel) {
	this->is_all_wheel_drive = all_wheel;
}

void sedan_c::inherit(vehicle_c* parent) {
	__super::set_brand(parent->get_brand());
	__super::set_model(parent->get_model());
	__super::set_horse_power(parent->get_horse_power());
	__super::set_year(parent->get_year());
}