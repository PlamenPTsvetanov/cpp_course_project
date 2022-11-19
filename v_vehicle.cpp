#include "v_vehicle.h"

int vehicle_c::get_id() {
	return this->id;
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

void vehicle_c::inherit(vehicle_c* veh) {
	this->set_brand(veh->get_brand());
	this->set_model(veh->get_model());
	this->set_horse_power(veh->get_horse_power());
	this->set_year(veh->get_year());
}

void vehicle_c::print_data() {
	cout << "\t|\t" << this->brand << "\t|\t" << this->model << "\t|\t" << this->year_of_construction << "\t|\t" << this->horse_power << "\t|" << endl;
}