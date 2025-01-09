#ifndef ATM_H
#define ATM_H

#include <string>
#include <iostream>
#include <map>
#include "Account.h"

class ATM {
    std::map<std::string, Account> accounts;
    std::string loggedInAccount;

    public:

    ATM() = default;

    void createAccount(std::string& accountNumber);
    bool login(std::string& accountNumber);
    void deposit(std::string& accountNumber, double amount);
    void withdraw(std::string& accountNumber, double amount);

};


#endif // ATM_H