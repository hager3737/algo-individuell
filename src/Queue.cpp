#include "../include/Queue.h"
#include "../include/Customer.h"

Queue::Queue() : amountOfCustomers(0) {}

void Queue::addCustomer(Customer& customer) {
    customers.push_back(customer);
    amountOfCustomers++;
}

int Queue::getAmountOfCustomers() {
    return amountOfCustomers;
}

std::vector<Customer> Queue::getAllCustomers() {
    for(Customer& customer : customers) {
        std::cout << "Ticket: " << customer.getQueueTicket();
    }
}