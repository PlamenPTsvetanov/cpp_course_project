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

string user_c::get_type()
{
    return this->type;
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

string user_c::get_admin_remark() {
    return this->admin_remark;
}

void user_c::set_admin_remark(string remark) {
    this->admin_remark = remark;
}

void user_c::set_type(string type) {
    this->type = type;
}

void user_c::inherit(user_c* parent) {
    this->set_name(parent->get_name());
    this->set_family(parent->get_family());
    this->set_username(parent->get_username());
    this->set_password(parent->get_password());
    this->set_admin_remark(parent->get_admin_remark());
}