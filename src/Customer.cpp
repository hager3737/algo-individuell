#include "../include/Customer.h"

Customer::Customer(std::string name, int queueTicket) 
    : name(name), queueTicket(queueTicket), arrivalTime(std::chrono::steady_clock::now()){}

int Customer::getQueueTicket() {
    return queueTicket;
}

std::string Customer::getName() {
    return name;
}

std::chrono::time_point<std::chrono::steady_clock> Customer::getArrivalTime() {
    return arrivalTime;
}



    