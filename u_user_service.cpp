#include "u_user_service.h"

void user_service::_create()
{
    cout << "Enter your first name:" << endl;
    cin >> in_name;
    cout << "Enter your family name:" << endl;
    cin >> in_family;
    cout << "Enter your username:" << endl;
    cin >> in_username;
    cout << "Enter your password:" << endl;
    cin >> in_password;
    cout << "Do you wish to\n\t1.buy\n\t2.sell" << endl;
    cin >> in_role;
    cout << "User created successfully!" << endl;
};
