#include "u_user.h"

user::user() {};

string user::get_name()
{
    return name;
};

string user::get_family()
{
    return family;
};

string user::get_username()
{
    return username;
};

string user::get_password()
{
    return password;
};

string user::get_role()
{
    return role;
};

void user::set_name(string nam)
{
    name = nam;
};

void user::set_family(string fam)
{
    family = fam;
};

void user::set_username(string usernam)
{
    username = usernam;
};

void user::set_password(string pass)
{
    password = pass;
};

void user::set_role(string rol)
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