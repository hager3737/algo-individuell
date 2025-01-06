#include "../include/Customer.h"

Customer::Customer(int queueTicket, std::string name, time_t arrival) 
    : queueTicket(queueTicket), name(name), arrival(arrival) {}

    