#include <iostream>

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
    int queueTicket;
    std::string name;
    time_t arrival;
    public:

    Customer(int queueTicket, std::string name, time_t arrival);
    int getQueueTicket();
};


#endif // CUSTOMER_H