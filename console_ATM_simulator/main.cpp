//
//  main.cpp
//  console_ATM_simulator
//
//  Created by Канапия on 05.09.2025.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <optional>
#include "bank_accaunt.hpp"
#include "readWriteLog.hpp"

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseAndClear() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    clearConsole();
}

int getTerminalWidth() {
    FILE* pipe = popen("tput cols", "r");
    
    if (!pipe) {
        return 80;
    }
    
    char buffer[128];
    std::string result = "";
    
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }
    
    pclose(pipe);
    try {
        return std::stoi(result);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        return 80;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        return 80;
    }
}

void textCenter(std::string str) {
    std::string text = str;
    int consoleWidth = getTerminalWidth();
    size_t textLength = text.length();

    size_t padding = 0;
    if (consoleWidth > textLength) {
        padding = (consoleWidth - textLength) / 2;
    }

    for (size_t i = 0; i < padding; ++i) {
        std::cout << " ";
    }

    std::cout << text << std::endl;
    std::cout << "" << std::endl;
}

struct AccountData {
    std::string cardNumber;
    double balance;
};

int main(int argc, const char * argv[]) {
    
    while (true) {
        clearConsole();
        textCenter("Welcome to ATM console simulator!");
        
        std::string cardNum;
        std::cout << "Enter your card number OR enter 0 to exit" << std::endl;
        std::getline(std::cin, cardNum);
        
        if (cardNum == "0") {
            std::cout << "Exiting. Goodbye!" << std::endl;
            return 0;
        }
        
        std::optional<bank_acc> bank1;
        
        if (cardNum == "0") {
            std::cout << "Exiting. Goodbye!" << std::endl;
            return 0;
        } else if (cardNum.length() != 16) {
            std::cerr << "Invalid card number. Try again." << std::endl;
            pauseAndClear();
            continue;
        } else {
            double startingBalance = 0.0;
            if (list.find(cardNum) != list.end()) {
                startingBalance = list[cardNum];
            }

            bank1.emplace(cardNum, startingBalance);
            std::cout << "Login successful. Welcome!" << std::endl;
        }
        
        clearConsole();

        if (bank1.has_value()) {
            clearConsole();
            bool running = true;
            while (running) {
                std::cout << "What would you like to do?" << std::endl;
                std::cout << "(1) Withdraw cash || (2) Top up card account || (3) Exit" << std::endl;

                int choice = 0;
                std::cin >> choice;
                clearConsole();
                
                switch (choice) {
                    case 1: {
                        textCenter("Withdraw cash!");
                        std::cout << "Your current balance is: " << bank1->return_accaunt() << std::endl;
                        double WithdrawAmount = 0.0;
                        std::cout << "Enter amount to Withdraw: ";
                        std::cin >> WithdrawAmount;

                        if (bank1->withdraw(WithdrawAmount)) {
                            std::cout << "Withdraw successful." << std::endl;
                            std::cout << "New balance: " << bank1->return_accaunt() << std::endl;
                        } else {
                            std::cerr << "Withdraw failed. Not enough funds or invalid amount." << std::endl;
                        }
                        
                        pauseAndClear();

                        break;
                    }
                    case 2: {
                        textCenter("Top up card account!");
                        std::cout << "Your current balance is: " << bank1->return_accaunt() << std::endl;

                        double depositAmount = 0.0;
                        std::cout << "Enter amount to deposit: ";
                        std::cin >> depositAmount;

                        bank1->deposit(depositAmount);
                        
                        pauseAndClear();
                        break;
                    }
                    case 3:
                        std::cout << "Goodbye! See you later)" << std::endl;
                        running = false;
                        break;
                    default:
                        std::cerr << "Invalid choice." << std::endl;
                        break;
                    }
                }
            }
    }
    
    return 0;
}
