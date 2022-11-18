#include "v_vehicle.h"

int vehicle_c::get_id() {
	return this->id;
}

string vehicle_c::get_type() {
	return this->type;
}

string vehicle_c::get_brand() {
	return this->brand;
}

string vehicle_c::get_model() {
	return this->model;
}

int vehicle_c::get_year() {
	return this->year_of_construction;
}

int vehicle_c::get_horse_power() {
	return this->horse_power;
}

void vehicle_c::set_type(string type) {
	if (type == "suv" || type == "truck" || type == "sedan")
	{
		this->type = type;
	}
	else {
		throw invalid_argument("No such type exists!\n");
	}
}

void vehicle_c::set_brand(string brand) {
	this->brand = brand;
}

void vehicle_c::set_model(string model) {
	this->model = model;
}

void vehicle_c::set_year(int year) {
	if (year < 1900 || year > 2022)
	{
		throw invalid_argument("Invalid year!\n");
	}
	this->year_of_construction = year;
}

void vehicle_c::set_horse_power(int horse_power) {
	if (horse_power < 0 || horse_power > 1400)
	{
		throw invalid_argument("Invalid horse power!\n");
	}
	this->horse_power = horse_power;
}