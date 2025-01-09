#include "../include/Queue.h"

void Queue::addCustomer(Customer& customer) {
    customers.push(customer);
}

Customer* Queue::getNextCustomer() {
    if(customers.empty()) {
        return nullptr;
    } 
    else {
        Customer* nextCustomer = new Customer (customers.front());
    customers.pop();
    return nextCustomer;
    }
}

bool Queue::isEmpty() {
    return customers.empty();
    
}

size_t Queue::size() {
    return customers.size();
}