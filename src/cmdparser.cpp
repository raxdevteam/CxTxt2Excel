#include "cmdparser.h"

CmdParser::CmdParser()
{

}

void CmdParser :: process_command(int argc, char **argv)
{
    if(argc>1 && (argc-1==4 || argc-1==5))
    {
        //Cmd : ./app file_name row2Skip sel_col delim_type [custom {if delim_type>2}]
        std::cout<<"App : "<<argv[0]<<std::endl;
        std::string filename=argv[1];
        std::cout<<"File : "<<filename<<std::endl;
        FileUtil fu;
        bool fileExists=fu.is_file_exists(argv[1]);
        if(fileExists)
        {
            int skipRow=atoi(argv[2]);
            std::cout<<"Skip row : "<<skipRow<<std::endl;

            std::string sel_col=argv[3];
            std::cout<<"Selected cols id : "<<sel_col<<std::endl;

            int delimeter=atoi(argv[4]);
            std::cout<<"Delimeter Type: "<<delimeter<<std::endl;

            TxtReader read;
            std::list<std::list<std::string>> dataList;
            if(delimeter>2){
                std::string custom_delimeter=argv[5];
                std::cout<<"Delimeter : "<<custom_delimeter<<std::endl;
                dataList = read.getNumericalData(argv[1], skipRow, sel_col, custom_delimeter);
            }else{
                dataList = read.getNumericalData(argv[1], skipRow, sel_col, delimeter);
                Txt2Xcel t2e;
                t2e.txt_2_xcel(dataList, read.sel_cols_list(sel_col));
               }
            ConsolePrint::print_txt_file_data(read.sel_cols_list(sel_col).size(), dataList);

        }else{
            std::cout<<"Invalid file name or file path"<<std::endl;
        }
    }
    else{
    std::cout<<"Insufficient paramater passed..!"<<std::endl;

    }
}
