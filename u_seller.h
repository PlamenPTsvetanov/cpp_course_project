#pragma once
#ifndef seller_h
#define seller_h

#include "u_user.h"
class seller_c : public user_c {
private:
	string email, telephone, payment_info;

public:
	string get_email();

	string get_telephone();

	string get_payment_info();

	void set_email(string email);

	void set_telephone(string telephone);

	void set_payment_info(string payment_info);
};

#endif // !seller_h
