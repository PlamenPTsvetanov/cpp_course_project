#pragma once
#ifndef buyer_h
#define buyer_h

#include "u_user.h"
class buyer_c : public user_c{
private:
	double wallet;

public:
	void set_wallet(double amount);

	double get_wallet();
};

#endif 
