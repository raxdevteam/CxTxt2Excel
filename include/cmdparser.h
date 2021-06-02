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
    void process_command(int argc, char *argv[]);
};

#endif // CMDPARSER_H
