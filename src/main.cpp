/* 
 * File:   main.cpp
 * Author: Rajeev
 *
 * Created on 2 October, 2020, 6:36 PM
 */


#include "cmdparser.h"

int main(int argc, char* argv[])
{
    CmdParser cmd;
              cmd.process_command(argc, argv);
    return 0;
}



