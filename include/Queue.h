#ifndef QUEUE_H
#define QUEUE_H

#include "Customer.h"
#include <iostream>
#include <vector>
#include <queue>


class Queue {
    std::queue<Customer> customers;

public: 
    void addCustomer(Customer& customer);
    Customer* getNextCustomer();
    bool isEmpty();
    size_t size();
};


#endif // QUEUE_H