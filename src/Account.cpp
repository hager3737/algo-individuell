#include "../include/Account.h"

Account::Account(std::string& accountNumber) 
    : accountNumber(accountNumber), balance(0.0){}

void Account::deposit(double amount) {
    if(amount <= 0) {
        throw std::invalid_argument("Deposit amount must be more than 0.");
    }
    balance = balance + amount;
} 

void Account::withdraw(double amount) {
    if(amount <= 0) {
        throw std::invalid_argument("Withdraw amount must be more than 0.");
    }
    if(balance < amount) {
        throw std::invalid_argument("Not enough money in the account.");
    }
    balance = balance - amount;
}

double Account::getBalance() {
    return balance;
}
