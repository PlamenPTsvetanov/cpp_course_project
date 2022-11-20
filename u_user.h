#pragma once
#ifndef user_h
#define user_h

#include "c_common.h"

class user_c
{
private:
    int id;
    string name, family, username, password, admin_remark, type;

public:
    user_c();

    int get_id();

    void set_id(int id);

    string get_name();

    string get_family();

    string get_username();

    string get_password();

    string get_admin_remark();

    string get_type();

    void set_name(string nam);

    void set_family(string fam);

    void set_username(string usernam);

    void set_password(string pass); 

    void set_admin_remark(string remark);

    void set_type(string type);

    void inherit(user_c* parent);
};
#endif
