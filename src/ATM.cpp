#include "../include/ATM.h"

void ATM::createAccount(std::string& accountNumber) {
    auto result = accounts.emplace(accountNumber, Account(accountNumber));
    if (!result.second) {
        std::cerr << "Account already exists.\n";
    } else {
        std::cout << "Account created successfully. You can now login!\n";
    }
}

bool ATM::login(std::string& accountNumber) {
    if(accounts.find(accountNumber) != accounts.end()) {
        loggedInAccount = accountNumber;
        std::cerr << "Login successful for account: " << accountNumber << std::endl;
        return true;
    }
    else {
        std::cerr << "Account not found." << std::endl;
        return false;
    }

}

void ATM::deposit(std::string& accountNumber, double amount) {
    auto it = accounts.find(accountNumber);
    if(it != accounts.end()) {
        it->second.deposit(amount);
        std::cout << "Deposited " << amount << " succesfully in to account " << accountNumber << std::endl;
    }
    else {
        std::cerr << "Account could not be found" << std::endl;
    }
}

void ATM::withdraw(std::string& accountNumber, double amount) {
    auto it = accounts.find(accountNumber);
    if(it != accounts.end()) {
        try {
        it->second.withdraw(amount);
        std::cout << "Withdrew " << amount << " succesfully from account " << accountNumber << std::endl;
        } 
        catch (std::exception& e) {
             std::cerr << e.what() << std::endl;
        }
    }
    else {
        std::cerr << "Account could not be found." << std::endl;
    }
}