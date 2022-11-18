#include "v_truck.h"

int truck_c::get_capacity() {
	return this->capacity;
}

int truck_c::get_weight() {
	return this->weight;
}

bool truck_c::get_is_special_use() {
	return this->is_special_use;
}

void truck_c::set_capacity(int capacity) {
	this->capacity = capacity;
}

void truck_c::set_weight(int weight) {
	this->weight = weight;
}

void truck_c::set_is_special_use(bool special_use) {
	this->is_special_use = special_use;
}