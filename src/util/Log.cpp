/* 
 * File:   Log.cpp
 * Author: Keo
 * 
 * Created on 12. březen 2014, 13:12
 */

#include "Log.h"

Log::Log()
{
    stringstream ss;
    ss << time(0);
    string str = ss.str();
    
    _logFile.open ("logs/Log-" + str + ".txt");
    _logFile << "[Greetings]\n\n";
}

Log::~Log()
{
    _logFile.close();
}


void Log::info(string type, string message)
{
    boost::to_lower(type);
    _logFile << "[" << type << "] " << message << "\n";
}

void Log::infonl(string type, string message)
{
    _logFile << "\n";
    info(type, message);
}