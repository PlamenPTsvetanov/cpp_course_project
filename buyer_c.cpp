#include "u_buyer.h"

void buyer_c::add_to_wallet(double amount) {
	this->wallet += amount;
}

double buyer_c::get_wallet() {
	return this->wallet;
}