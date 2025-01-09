#include "../include/Queue.h"

void Queue::addCustomer(Customer& customer) {
    customers.push(customer);
}

Customer Queue::getNextCustomer() {
    if(customers.empty()) {
        throw std::out_of_range("Queue is empty!");
    }
    Customer nextCustomer = customers.front();
    customers.pop();
    return nextCustomer;
}

bool Queue::isEmpty() {
    return customers.empty();
    
}

size_t Queue::size() {
    return customers.size();
}