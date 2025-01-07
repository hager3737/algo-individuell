#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <chrono>

class Queue;

class Customer {
    int queueTicket;
    std::string name;
    time_t arrival;
    int amountOfCustomers;

    public:
    Customer(std::string name, Queue& queue);
    int getAmountOfCustomers();
    int getQueueTicket();
};


#endif // CUSTOMER_H