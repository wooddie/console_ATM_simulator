//
//  main.cpp
//  console_ATM_simulator
//
//  Created by Канапия on 05.09.2025.
//

#include <iostream>
#include "string"
#include "cstdio"
#include "cstdlib"
#include "login_page.hpp"

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int getTerminalWidth() {
    FILE* pipe = popen("tput cols", "r");
    
    if (!pipe) {
        return 80; // Значение по умолчанию
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
        return 80; // Значение по умолчанию при ошибке
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        return 80; // Значение по умолчанию при ошибке
    }
}

int main(int argc, const char * argv[]) {
    std::string text = "Welcome to ATM console simulator!";
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
    
    clearConsole();
    
    std::cout << "hello" << std::endl;
    
    return 0;
}
