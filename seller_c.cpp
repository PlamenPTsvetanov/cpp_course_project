#include "u_seller.h"

string seller_c::get_email() {
	return this->email;
};

string seller_c::get_telephone() {
	return this->telephone;
};

string seller_c::get_payment_info() {
	return this->payment_info;
};

void seller_c::set_email(string email) {
	this->email = email;
};

void seller_c::set_telephone(string telephone) {
	this->telephone = telephone;
};

void seller_c::set_payment_info(string payment_info) {
	this->payment_info = payment_info;
};