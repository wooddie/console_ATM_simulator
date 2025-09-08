//
//  readWriteLog.hpp
//  console_ATM_simulator
//
//  Created by Канапия on 07.09.2025.
//

#ifndef readWriteLog_hpp
#define readWriteLog_hpp

#include <stdio.h>
#include <string>
#include <map>

extern std::unordered_map<std::string, double> list;

std::string readLog();
void writeCard(std::string str, double num);

#endif /* readWriteLog_hpp */
