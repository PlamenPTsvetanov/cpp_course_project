#include "connection.h"
#include "service_header.h"


void printPrimaryMenu() {
    cout << "----------WELCOME----------" << endl;
    cout << "Do you wish to\n\t1.log in\n\t2.sign up\n\t0.Exit" << endl;
}

int main()
{
    seller_service service;
    service._log_in("SELLERS");
    service._delete();
    return 0;
}



