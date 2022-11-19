#include "v_motorcycle.h"

bool motorcycle_c::get_is_modded() {
	return this->is_modded;
}

bool motorcycle_c::get_is_track() {
	return this->is_track;
}

void motorcycle_c::set_is_modded(bool modded) {
	this->is_modded = modded;
}


void motorcycle_c::set_is_track(bool track) {
	this->is_track = track;
}