#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>

class Customer;

class Queue {
    std::vector<Customer> customers;
    int amountOfCustomers;

public: 
    Queue();
    void addCustomer(Customer& customer);
    int getAmountOfCustomers();
    std::vector<Customer> getAllCustomers();
};


#endif // QUEUE_H