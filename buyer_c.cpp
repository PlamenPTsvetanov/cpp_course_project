#include "u_buyer.h"

void buyer_c::set_wallet(double amount) {
	this->wallet += amount;
}

double buyer_c::get_wallet() {
	return this->wallet;
}