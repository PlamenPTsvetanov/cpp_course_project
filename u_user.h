#pragma once
#ifndef user_h
#define user_h

#include "c_common.h"

class user
{
private:
    int id;
    string name, family, username, password, role;

public:
    user();

    string get_name();

    string get_family();

    string get_username();

    string get_password();

    string get_role();

    void set_name(string nam);

    void set_family(string fam);

    void set_username(string usernam);

    void set_password(string pass);

    void set_role(string rol);
};
#endif