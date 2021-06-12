#ifndef CMDPARSER_H
#define CMDPARSER_H

//#include <iostream>
//#include <string>

#include "txt2xcel.h"

//Macros to show OS specific message
#if defined __linux__ || defined __apple__ || defined __bsd__
    #define OS_SPECIFIC_MSG(x,m) if(x==1)std::cout<<m<<std::endl
#elif _WIN32
    #define OS_SPECIFIC_MSG(x,m) if(x==2)std::cout<<m<<std::endl
#else
  #error "Unknown platform"
#endif


class CmdParser
{
public:
    CmdParser();
    void help_cmd();
    void process_command(int argc, char *argv[]);
};

#endif // CMDPARSER_H
