#include "v_two_wheeler.h"

bool two_wheeler_c::get_is_modded() {
	return this->is_modded;
}

bool two_wheeler_c::get_is_track() {
	return this->is_track;
}

void two_wheeler_c::set_is_modded(bool modded) {
	this->is_modded = modded;
}


void two_wheeler_c::set_is_track(bool track) {
	this->is_track = track;
}