#pragma once
#ifndef user_service_h
#define user_service_h
#include "u_user.h"

class user_service
{
private:
    user user;
    string in_name, in_family, in_username, in_password, in_role;

public:
    void _create();
};
#endif