#include "connection.h"
#include "u_seller_service.h"
#include "u_buyer_service.h"
int main()
{
    seller_service service;
    service._log_in();
    service._update(45);
    return 0;
}