#ifndef CMDPARSER_H
#define CMDPARSER_H

#include <iostream>
#include <string>

#include "consoleprint.h"
#include "txtreader.h"
#include "fileutil.h"
#include "txt2xcel.h"


class CmdParser
{
public:
    CmdParser();
    void test();
    void createDir(std::string path);
    void help_cmd();
    void process_command(int argc, char *argv[]);
};

#endif // CMDPARSER_H
