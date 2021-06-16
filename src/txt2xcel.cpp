#include "txt2xcel.h"

Txt2Xcel::Txt2Xcel()
{

}

Txt2Xcel::~Txt2Xcel()
{

}


Txt2Xcel::Txt2Xcel(std::string _fileName,  int _skipRowNo, std::string _cols, int _colSeparatorType)
{
    fileName=_fileName;
    skipRowNo=_skipRowNo;
    cols=_cols;
    col=TxtReader::sel_col_index_list(cols);
    colSeparatorType=_colSeparatorType;
    grpColStart=0;//1
    colCount=col.size();
    grpColEnd=colCount;//+1

    std::string file_directory=FileUtil::get_file_directory(fileName);
    char* fn=get_filename_timeStamp();
    file_directory.append(fn).append(".xlsx");
    std::cout<<"Converted file path : "<<file_directory<<std::endl;

    workbook   = workbook_new(file_directory.c_str());//"Report.xlsx");
    worksheet  = workbook_add_worksheet(workbook, "Data");

    /* Set the properties in the workbook. */
    add_doc_properties();
    add_doc_cust_prop();

}
Txt2Xcel::Txt2Xcel(std::string _fileName,  int _skipRowNo, std::string _cols, int _colDif, int _colSeparatorType)
{
    fileName=_fileName;
    skipRowNo=_skipRowNo;
    cols=_cols;
    col=TxtReader::sel_col_index_list(cols);
    colSeparatorType=_colSeparatorType;
    colDif=_colDif;
    grpColStart=0;//1
    colCount=col.size();
    tcc=colDif+colCount;
    grpColEnd=colCount;//+1
    std::cout<<"Col div : "<<colDif<<" count : "<<colCount<<std::endl;

    std::string file_directory=FileUtil::get_file_directory(fileName);
    //file_directory.append("Report.xlsx");
    char* fn=get_filename_timeStamp();
    file_directory.append(fn).append(".xlsx");
    std::cout<<"Converted file path : "<<file_directory<<std::endl;

    workbook   = workbook_new(file_directory.c_str());//"Report.xlsx");
    worksheet  = workbook_add_worksheet(workbook, "Data");

    /* Set the properties in the workbook. */
    add_doc_properties();
    add_doc_cust_prop();

}
Txt2Xcel::Txt2Xcel(int opt, std::string _fileName,  int _skipRowNo, std::string _cols, int _colSeparatorType)
{
    fileName=_fileName;
    skipRowNo=_skipRowNo;
    cols=_cols;
    col=TxtReader::sel_col_index_list(cols);
    colSeparatorType=_colSeparatorType;
    grpColStart=opt;//0;//1
    colCount=col.size();
    grpColEnd=colCount;//+1

    std::string file_directory=FileUtil::get_file_directory(fileName);
    char* fn=get_filename_timeStamp();
    file_directory.append(fn);
    dirPath=file_directory;
    std::cout<<"Converted file path : "<<file_directory<<std::endl;

/*    workbook   = workbook_new(file_directory.c_str());//"Report.xlsx");
    worksheet  = workbook_add_worksheet(workbook, "Data");
    add_doc_properties();
    add_doc_cust_prop();
    */

}

void Txt2Xcel :: add_doc_cust_prop(/*lxw_workbook *workbook*/)
{
    lxw_datetime   datetime  = {2021, 05, 12,  0, 0, 0.0};

    // Set some custom document properties in the workbook.
    workbook_set_custom_property_string  (workbook, "Checked by",      "Anjali Shah");
    workbook_set_custom_property_datetime(workbook, "Date completed",   &datetime);
    workbook_set_custom_property_number  (workbook, "Document number",  12345);
    workbook_set_custom_property_number  (workbook, "Reference number", 1.2345);
    workbook_set_custom_property_boolean (workbook, "Has Review",       1);
    workbook_set_custom_property_boolean (workbook, "Signed off",       0);

}

void Txt2Xcel :: add_doc_properties(/*lxw_workbook *wb*/)
{

    char _title[] =    "Report";
    char _subject[] =  "With the comment";
    char _author[]   = "Rajeev Rai";
    char _manager[]  = "R Rajeev";
    char _company[]  = "Rax Dev Team";
    char _category[] = "Report";
    char _keywords[] = "C, C++, Excel, Properties";
    char _comments[] = "Created with libxlsxwriter";
    char _status[]   = "Final";
    // Create a properties structure and set some of the fields.
    doc_properties={
        .title = _title,
        .subject = _subject,
        .author=_author,
        .manager=_manager,
        .company=_company,
        .category=_category,
        .keywords=_keywords,
        .comments=_comments,
        .status=_status,
       };
    workbook_set_properties(workbook, &doc_properties);

}

char* Txt2Xcel :: get_filename_timeStamp()
{
  time_t rawtime;
  struct tm * timeinfo;
  char *buffer;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer, 80 ,"%F_%T",timeinfo);
  return buffer;
}

void Txt2Xcel :: write_excel_data(std::string _title, std::vector<std::vector<double>> _dataRowList)
{
    std::cout<<"Col title :  "<<_title<<std::endl;
    const char *groupTitle=_title.c_str(); //replace with filename without extesion
    worksheet_merge_range(worksheet, 0, grpColStart, 0, grpColEnd-1, groupTitle, merge_format);
    worksheet_set_row(worksheet, 0, LXW_DEF_ROW_HEIGHT, bold);

    int rowId=1, colId=0;

    for(std::vector<double> dataCol : _dataRowList)
    {
        for(int col=grpColStart; col<grpColEnd; col++)
        {
            std::cout<<"Rx: "<<rowId<<" Cx: "<<col<<" Cz: "<<colId<<" Dx: "<<dataCol[colId]<<" ";
            worksheet_write_number(worksheet, rowId, col, dataCol[colId],  NULL);
            colId++;
        }
        std::cout<<std::endl;
        rowId++;colId=0;
    }

    std::cout<<"Processing file id : "<<processingFileId<<std::endl;
    if(processingFileId==1 || processingFileId==fileCount){
            std::cout<<"Grp Sx : "<<grpColStart<<" Ex : "<<grpColEnd<<std::endl;
            worksheet_set_column_opt(worksheet, grpColStart, grpColEnd-2,  5, NULL, &col_options);

        }else{
        std::cout<<"Grp Sxm : "<<grpColStart<<" Exm : "<<grpColEnd<<std::endl;

        worksheet_set_column_opt(worksheet, grpColStart, grpColEnd-2,  5, NULL, &col_options);
       }
        grpColStart+=tcc;grpColEnd+=tcc;processingFileId++;
}

void Txt2Xcel :: wx_mfx_2_mex()
{
    FileUtil::make_directory(dirPath);
}

void Txt2Xcel :: wx_of_2_ex()
{
    TxtReader txtRdr;
    std::vector<std::vector<double>> dataRowList=txtRdr.parseTxt2Number_VECT(fileName, skipRowNo, cols, colSeparatorType);
    int rowId=0, colId=0;

    for(std::vector<double> dataCol : dataRowList)
    {
        for(int col=grpColStart; col<grpColEnd; col++)
        {
            std::cout<<"Rx: "<<rowId<<" Cx: "<<col<<" Cz: "<<colId<<" Dx: "<<dataCol[colId]<<" ";
            worksheet_write_number(worksheet, rowId, col, dataCol[colId],  NULL);
            colId++;
        }
        std::cout<<std::endl;
        rowId++;colId=0;
    }

    workbook_close(workbook);

}

void Txt2Xcel :: wx_mfx_2_one_sx(/*std::string _file_name*/)
{

    bold = workbook_add_format(workbook);
    format_set_bold(bold);

    merge_format = workbook_add_format(workbook);

    /* Configure a format for the merged range. */
    format_set_align(merge_format, LXW_ALIGN_CENTER);
    format_set_align(merge_format, LXW_ALIGN_VERTICAL_CENTER);
    format_set_bold(merge_format);
    format_set_bg_color(merge_format, LXW_COLOR_YELLOW);
    format_set_border(merge_format, LXW_BORDER_THIN);

    /* Increase the cell size of the merged cells to highlight the formatting. */
    worksheet_set_column(worksheet, 1, 3, 12, NULL);


    //lxw_row_col_options options_0 = {.hidden = 0, .level = 1, .collapsed = 0};
    col_options = {.hidden = 0, .level = 1, .collapsed = 1};
    //lxw_row_col_options options_2 = {.hidden = 0, .level = 1, .collapsed = 2};


    std::list<std::string> file_path_list=FileUtil::read_directory_file_path(fileName);
    std::vector<std::string> file_title_list=FileUtil::get_file_name_list_without_extension(fileName);
    int fileCount=file_path_list.size();
    std::cout<<"File cont : "<<fileCount<<std::endl;
    std::cout<<"File name cont : "<<file_title_list.size()<<std::endl;
    processingFileId=1; int max_col=col.size();
    TxtReader txtRdr;
    for(std::string file_name : file_path_list)
    {
        std::cout<<"Processing file : "<<file_name<<std::endl;
        std::vector<std::vector<double>> dataList=txtRdr.parseTxt2Number_VECT(file_name, skipRowNo, cols, colSeparatorType);
        ConsolePrint::print_txt_file_data_vect(max_col, dataList);
        write_excel_data(file_title_list[processingFileId-1], dataList);//txtRdr.parseTxt2Number_VECT(file_name,6,"1,2,3", 0));
    }

    workbook_close(workbook);

}
