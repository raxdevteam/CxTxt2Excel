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
                t2e.txt_2_xcel(dataList, read.sel_col_index_list(sel_col));
               }
            ConsolePrint::print_txt_file_data(read.sel_col_index_list(sel_col).size(), dataList);

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
    std::cout<<"\nUsage : \n\tCxTxt2Excel.exe <directory> <fileExtension> <skipRows> -c <SelectedColumn> <groupSeparation> <dataSeparator>"<<std::endl;
    std::cout<<"Parameters : "<<std::endl;
    std::cout<<"\t<directory_path>    directory which contains all files"<<std::endl;
    std::cout<<"\t<fileExtension>     Extension of files which are going to processed"<<std::endl;
    std::cout<<"\t<skipRowsNumber>    Number of rows to skip from starting"<<std::endl;
    std::cout<<"\t<selectedColumn>    Selected columns index start from zero"<<std::endl;
    std::cout<<"\t<groupSeparation>   Group separation by number of columns"<<std::endl;
    std::cout<<"\t<dataSeparatorId>   Files contains data separator"<<std::endl;
    std::cout<<"\t                    Id [0-Comma 1-Tab 2-Space]"<<std::endl;
    std::cout<<"Example : "<<std::endl;
    std::cout<<"\tCxTxt2Excel.exe data .txt 5 -c 1,3,5 1 1"<<std::endl;
}

void CmdParser :: createDir(std::string path)
{


        #if defined __linux__ || defined __apple__ || defined __bsd__
         // mkdir(path.c_str(), 0777);
        #elif _WIN32
          wchar_t* wtext = winUtils::stringToLPWSTR(path);
        CreateDirectoryW(wtext, NULL);
          delete [] wtext;
        #else
          #error "Unknown platform"
        #endif


}

void CmdParser :: test()
{
    Txt2Xcel t2x;
    TxtReader trd;
    std::list<std::list<double>> dataList=trd.parseTxt2Number_LIST("./1.txt",6,"1,2,3",0);
    t2x.writeExcelData("1", dataList);
}
