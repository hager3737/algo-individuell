#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

class Account {
    std::string accountNumber;
    double balance;

    public:
    Account(std::string& accountNumber);
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);
};


#endif // ACCOUNT_H