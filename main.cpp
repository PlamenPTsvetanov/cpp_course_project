#include "connection.h"
#include "service_header.h"


void printPrimaryMenu() {
    cout << "----------WELCOME----------" << endl;
    cout << "Do you wish to\n\t1.log in\n\t2.sign up\n\t0.Exit" << endl;
}

int main()
{
    ad_service a_service;
    seller_service s_service;
    
    s_service._log_in("SELLERS");
    int id  =s_service._logged_in_id();
    cout << id << endl;
    a_service._create(id, 1, "sedan");
    return 0;
}



