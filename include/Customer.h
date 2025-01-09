#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <chrono>

class Customer {
    int queueTicket;
    std::string name;
    std::chrono::time_point<std::chrono::steady_clock> arrivalTime;

    public:
    Customer(std::string name, int queueTicket);
    std::string getName();
    int getQueueTicket();
    std::chrono::time_point<std::chrono::steady_clock> getArrivalTime();
};


#endif // CUSTOMER_H