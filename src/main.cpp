/* 
 * File:   main.cpp
 * Author: Rajeev
 *
 * Created on 2 October, 2020, 6:36 PM
 */


#include "cmdparser.h"
//#include "passwordmasking.h"
#include "txt2xcel.h"

int main(int argc, char* argv[])
{
    /*CmdParser cmd;
              cmd.process_command(argc, argv);*/

    Txt2Xcel t2x;
     t2x.createExcel();

/*CmdParser cmd;
cmd.test();
    /*PasswordMasking pswMask;
    pswMask.echo_with_mask();
    pswMask.echo_hide();*/
    return 0;

}



