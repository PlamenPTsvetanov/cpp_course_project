#include "connection.h"
#include "service_header.h"


void printPrimaryMenu() {
    cout << "----------WELCOME----------" << endl;
    cout << "Do you wish to\n\t1.log in\n\t2.sign up\n\t0.Exit" << endl;
}

int main()
{
    user_service u_service;


    int command = -1;
    printPrimaryMenu();

    cin >> command;
    while (command != 0) {
        if (command == 1)
        {

        }

        cin >> command;
    }
  
    return 0;
}



