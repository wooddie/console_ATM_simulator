//
//  bank_accaunt.hpp
//  console_ATM_simulator
//
//  Created by Канапия on 06.09.2025.
//

#ifndef bank_accaunt_hpp
#define bank_accaunt_hpp

#include <stdio.h>
#include "string"
#include "iostream"
#include "readWriteLog.hpp"

class bank_acc {
public:
    bank_acc(std::string cardNumber, double balance)
    : card_num(std::move(cardNumber)), accaunt(std::move(balance)) {}
    
    double return_accaunt() const { return accaunt; };
    
    void deposit(double amount) {
        if (amount > 0) {
            accaunt += amount;
            list[card_num] = accaunt;  // ✅ синхронизируем "базу"
        }
        std::cout << "Deposit successful!" << std::endl;
        std::cout << "Current balance: " << return_accaunt() << std::endl;
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && accaunt >= amount) {
            accaunt -= amount;
            list[card_num] = accaunt;
            return true;
        }
        return false;
    }
private:
    std::string card_num = "";
    double accaunt = 0.0;
};

#endif /* bank_accaunt_hpp */
