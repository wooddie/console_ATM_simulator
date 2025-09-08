//
//  readWriteLog.cpp
//  console_ATM_simulator
//
//  Created by Канапия on 07.09.2025.
//

#include "readWriteLog.hpp"
#include <map>
#include <iostream>

std::unordered_map<std::string, double> list;

std::string readLog() {
    
    return "";
}

void writeCard(const std::string& cardNumber, double amount) {
    list[cardNumber] += amount;
    std::cout << "Deposit successful!" << std::endl;
    std::cout << "Current balance: " << list[cardNumber] << std::endl;
}

std::string writeLog(std::string str);
