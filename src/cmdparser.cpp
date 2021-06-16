#include "cmdparser.h"

CmdParser::CmdParser()
{

}

void CmdParser :: process_command(int argc, char *argv[])
{
    if(argc>1 && (argc-1==4))
    {
        //Cmd : ./app file_name row2Skip sel_col delim_type [custom {if delim_type>2}]
        std::cout<<"App : "<<argv[0]<<std::endl;
        std::string filename=argv[1];
        std::cout<<"File : "<<filename<<std::endl;

        bool fileExists=FileUtil::is_file_exists(argv[1]);
        if(fileExists)
        {
            int skipRow=atoi(argv[2]);
            std::cout<<"Skip row : "<<skipRow<<std::endl;

            std::string sel_col=argv[3];
            std::cout<<"Selected cols id : "<<sel_col<<std::endl;

            //int col_diff=atoi(argv[4]);
            //std::cout<<"Col diff: "<<col_diff<<std::endl;

            int delimeter_opt=atoi(argv[4]);
            std::cout<<"Delimeter Type: "<<delimeter_opt<<std::endl;
            //std::string delimeter_type[3]={",", "\t", " "};

            Txt2Xcel txt_xl(0,filename, skipRow, sel_col, delimeter_opt);
                     txt_xl.wx_mfx_2_mex();
                    // txt_xl.wx_of_2_ex();
                     //filename, skipRow, sel_col, col_diff, delimeter_opt);
                     //txt_xl.wx_mfx_2_one_sx();

        }else{
            std::cout<<"Invalid file name or file path"<<std::endl;
        }
    }
    else{
//    std::cout<<"Insufficient paramater passed..!"<<std::endl;
        help_cmd();
    }
}

void CmdParser :: help_cmd()
{
    std::cout<<"\n[Error] : Invalid number of parameters...!"<<std::endl;

    OS_SPECIFIC_MSG(1,"\nUsage : \n\t./CxTxt2Excel <filename> <skipRows> -c <SelectedColumn> <groupSeparation> <dataSeparator>");
    OS_SPECIFIC_MSG(2,"\nUsage : \n\tCxTxt2Excel.exe <filename> <skipRows> -c <SelectedColumn> <groupSeparation> <dataSeparator>");

    std::cout<<"Parameters : "<<std::endl;
    std::cout<<"\t<filename>          Filename to proceed"<<std::endl;
    std::cout<<"\t<skipRowsNumber>    Number of rows to skip from starting"<<std::endl;
    std::cout<<"\t<selectedColumn>    Selected columns index start from one"<<std::endl;
    std::cout<<"\t<groupSeparation>   Group separation by number of columns"<<std::endl;
    std::cout<<"\t<dataSeparatorId>   Files contains data separator"<<std::endl;
    std::cout<<"\t                    Id [0-Comma 1-Tab 2-Space]"<<std::endl;
    std::cout<<"Example : "<<std::endl;

    OS_SPECIFIC_MSG(1,"\t./CxTxt2Excel data.txt 5 -c 1,3,5 1 1");
    OS_SPECIFIC_MSG(2,"\tCxTxt2Excel.exe data.txt 5 -c 1,3,5 1 1");

}
