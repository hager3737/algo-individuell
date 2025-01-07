#include "../include/Customer.h"
#include "../include/Queue.h"

Customer::Customer(std::string name, Queue& queue) 
    : name(name){
        auto now = std::chrono::system_clock::now();
        arrival = std::chrono::system_clock::to_time_t(now);

        if(queue.getAmountOfCustomers() > 0) {
            queueTicket = queue.getAmountOfCustomers() + 1;
        } 
        queueTicket = queue.getAmountOfCustomers();
    }

int Customer::getAmountOfCustomers() {
    return queueTicket;
}

int Customer::getQueueTicket() {
    return queueTicket;
}



    