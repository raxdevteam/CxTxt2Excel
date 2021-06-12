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
   /*FileUtil fu;
   /*std::cout<<"--------File path list----------"<<std::endl;
   std::list<std::string> filePathList=fu.show_file_path(".txt");
   for(std::string fileName : filePathList) {
       std::cout<<fileName<<std::endl;
   }
   std::cout<<"\n---File path-------"<<std::endl;
   fu.get_file_directory(argv[1]);
    /*CmdParser cmd;
              cmd.process_command(argc, argv);
*/
    Txt2Xcel t2x;
     t2x.wxExData2OneSx(argv[1]);


/*CmdParser cmd;
cmd.test();
    /*PasswordMasking pswMask;
    pswMask.echo_with_mask();
    pswMask.echo_hide();*/
    return 0;

}



