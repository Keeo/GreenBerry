/* 
 * File:   Log.h
 * Author: Keo
 *
 * Created on 12. březen 2014, 13:12
 */

#ifndef LOG_H
#define	LOG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/System.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

class Log
{
    public:
        static Log& getInstance()
        {
            static Log    instance;
            return instance;
        }
        
        void info(string type, string message);
        void infonl(string type, string message);
        
    private:
        
        ofstream _logFile;
        Log();                 
        Log(Log const&);              // Don't Implement
        void operator=(Log const&); // Don't implement
        ~Log();
};
#endif	/* LOG_H */

