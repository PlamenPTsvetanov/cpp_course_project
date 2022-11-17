#pragma once
#ifndef user_service_h
#define user_service_h
#include "u_user.h"

class user_service
{
protected:
    user_c *user;
    string in_name, in_family, in_username, in_password;
    int in_role;

public:
    user_service();

    void _create();

    void _update(int id);

    user_c* _log_in();

    void _log_out();

    bool user_exists(int id);

    int _logged_in_id();

protected:
    int get_id();
};
#endif