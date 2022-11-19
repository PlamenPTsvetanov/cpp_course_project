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

    user_c* _create();

    user_c* _update(int id);

    void _delete(int id, string table);

    user_c* _log_in(string table);

    void _log_out();

    void user_exists(int id, string table);

    int _logged_in_id();
};
#endif