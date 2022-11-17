#include "s_ad.h"

int ad_c::get_id(){
	return this->id;
};

int ad_c::get_seller_id(){
	return this->seller_id;
};

int ad_c::get_vehicle_id(){
	return this->vehicle_id;
};

string ad_c::get_title(){
	return this->title;
};

double ad_c::get_price(){
	return this->price;
};

string ad_c::get_date(){
	string ret_date = to_string(date.year) + "-" + to_string(date.month) + "-" + to_string(date.day);
	return ret_date;
};
string ad_c::get_additional_info(){
	return this->additional_info;
};

void ad_c::set_id(int id){
	this->id = id;
};

void ad_c::set_seller_id(int seller){
	this->seller_id = seller;
};

void ad_c::set_vehicle_id(int vehicle){
	this->vehicle_id = vehicle;
};

void ad_c::set_title(string title){
	this->title = title;
};

void ad_c::set_price(double price){
	this->price = price;
};

void ad_c::set_date(){
	time_t now = time(0);


	tm* local = localtime(&now);
	this->date.day = local->tm_mday;
	this->date.month = local->tm_mon + 1;
	this->date.year = local->tm_year + 1900;
};

void ad_c::set_additional_info(string info){
	this->additional_info = info;
};