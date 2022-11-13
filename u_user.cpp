#include "u_user.h"

user_c::user_c() {};

int user_c::get_id() {
    return this->id;
};

string user_c::get_name()
{
    return this->name;
};

string user_c::get_family()
{
    return this->family;
};

string user_c::get_username()
{
    return this->username;
};

string user_c::get_password()
{
    return this->password;
};

string user_c::get_role()
{
    return this->role;
};

void user_c::set_id(int id)
{
    this->id = id;
};

void user_c::set_name(string nam)
{
    name = nam;
};

void user_c::set_family(string fam)
{
    family = fam;
};

void user_c::set_username(string user_cnam)
{
    username = user_cnam;
};

void user_c::set_password(string pass)
{
    password = pass;
};

void user_c::set_role(string rol)
{
    if (rol == "seller")
    {
        role = "seller";
    }
    else if (rol == "admin")
    {
        role = "admin";
    }
    else
    {
        role = "buyer";
    }
};