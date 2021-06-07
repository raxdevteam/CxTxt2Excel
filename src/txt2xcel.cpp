#include "txt2xcel.h"

Txt2Xcel::Txt2Xcel()
{

}

Txt2Xcel::~Txt2Xcel()
{

}


Txt2Xcel::Txt2Xcel(std::string _dirPath, std::string _fileName, int _skipRowNo, std::list<int> _col, std::string _colSeparator)
{
    dirPath=_dirPath;
    fileName=_fileName;
    skipRowNo=_skipRowNo;
    col=_col;
    colSeparator=_colSeparator;
    colCount=col.size();
    grpColEnd=colCount+1;

    //setFileProperty();

    std::cout<<"Dir path:"<<dirPath;
    init_excel_file();
}
Txt2Xcel::Txt2Xcel(std::string _dirPath,  std::string _fileName,  std::string _fileExtension, int _skipRowNo, std::list<int> _col, int _colDif, std::string _colSeparator)
{

}
Txt2Xcel::Txt2Xcel(std::string _dirPath, std::string _fileName, int _skipRowNo, std::list<int> _col, int _colDif, std::string _colSeparator)
{
    dirPath=_dirPath;
    fileName=_fileName;
    skipRowNo=_skipRowNo;
    col=_col;
    colSeparator=_colSeparator;
    colDif=_colDif;
    grpColStart=1;//1
    colCount=col.size();
    tcc=colDif+colCount;
    grpColEnd=colCount;//+1
    std::cout<<"Col div : "<<colDif<<"count : "<<colCount;
 //   setFileProperty();
    init_excel_file();
}

void Txt2Xcel :: writeExcelData(std::string _title, std::list<std::list<double>> &_dataList)
{
    //worksheet_merge_range(worksheet, 0, 0, 0, 2, _title.c_str(), merge_format);
    /* Add bold format to the first row. */
    //worksheet_set_row(worksheet, 0, LXW_DEF_ROW_HEIGHT, bold);
    /*xlsx.write(1,grpColStart, processingFileId);
    qDebug()<<"Grp  S : "<<grpColStart<<" E : "<<grpColEnd;
    xlsx.mergeCells(CellRange(1,grpColStart,1,grpColEnd),formatAlign);
*/
    //int row=2,colId=0;//1 for heading
    int max_cols, row_id=1, col_id=0;

    for(std::list<double> data : _dataList) {
        /*for (int col = grpColStart; col <= grpColEnd; ++col){
          //  xlsx.write(row, col, data[colId]);colId++;
            worksheet_write_number(worksheet, row,col, data[colId], NULL);   colId++;
        }
        row++;colId=0;*/
        max_cols=data.size();
        for(double val : data)
        {
            /*for(int i=0; i<max_cols; i++)
            {
                worksheet_write_string(worksheet, row_id, i, val.c_str(), NULL);
            }*/
            if(col_id==max_cols-1)
                col_id=0;
            else
                col_id++;

           // worksheet_write_number(worksheet, row_id, col_id, val, NULL);
            std::cout<<"r:"<<row_id<<" c:"<<col_id<<" v:"<<val<<std::endl;

        }
        row_id++;
    }

  /* if(processingFileId==1 || processingFileId==fileCount){
        //qDebug()<<"Grp Sx : "<<grpColStart<<"Ex : "<<grpColEnd;
       // xlsx.groupColumns(grpColStart, grpColEnd, false);
    }else{
    //xlsx.groupColumns(grpColStart, grpColEnd);
    }
    grpColStart+=tcc;grpColEnd+=tcc;processingFileId++;*/

   // worksheet_set_column_opt(worksheet, /*COLS("I:J")*/0,1,  5, NULL, &col_options);
    //workbook_close(workbook);
}

/*void Txt2Xcel ::  writeExcelData(std::vector<std::vector<double>> &_dataList)
{
    xlsx.write(1,grpColStart, _title);
    qDebug()<<"Grp  S : "<<grpColStart<<" E : "<<grpColEnd;
    xlsx.mergeCells(CellRange(1,grpColStart,1,grpColEnd),formatAlign);

    int row=2,colId=0;//1 for heading
    foreach(QList<double> data, dataList) {
        for (int col = grpColStart; col <= grpColEnd; ++col){
            xlsx.write(row, col, data[colId]);colId++;
        }
        row++;colId=0;
    }

   if(processingFileId==1 || processingFileId==fileCount){
        qDebug()<<"Grp Sx : "<<grpColStart<<"Ex : "<<grpColEnd;
        xlsx.groupColumns(grpColStart, grpColEnd, false);
    }else{
    xlsx.groupColumns(grpColStart, grpColEnd);
    }
    grpColStart+=tcc;grpColEnd+=tcc;processingFileId++;
}
*/
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

void Txt2Xcel :: init_excel_file()
{
    workbook   = workbook_new("Report.xlsx");
    worksheet  = workbook_add_worksheet(workbook, "Outline Columns");

    /* Set the properties in the workbook. */
    add_doc_properties();
    add_doc_cust_prop();

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


    /*
     * Example 3: Create a worksheet with outlined columns.
     */
    //lxw_row_col_options options_0 = {.hidden = 0, .level = 1, .collapsed = 0};
    col_options = {.hidden = 0, .level = 1, .collapsed = 1};
    //lxw_row_col_options options_2 = {.hidden = 0, .level = 1, .collapsed = 2};

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



void Txt2Xcel :: createExcel()
{
    workbook   = workbook_new("Report.xlsx");
    worksheet  = workbook_add_worksheet(workbook, "Outline Columns");

    /* Set the properties in the workbook. */
    add_doc_properties();
    add_doc_cust_prop();

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

    dirPath="./data";
    fileName="./data/data.txt";
    skipRowNo=6;
    col.push_back(1);col.push_back(2),col.push_back(3);
    colSeparator=",";
    colDif=1;
    grpColStart=0;//1
    colCount=col.size();
    tcc=colDif+colCount;
    grpColEnd=colCount;//+1
    std::cout<<"Col div : "<<colDif<<" count : "<<colCount<<std::endl;

    //lxw_row_col_options options_0 = {.hidden = 0, .level = 1, .collapsed = 0};
    col_options = {.hidden = 0, .level = 1, .collapsed = 1};
    //lxw_row_col_options options_2 = {.hidden = 0, .level = 1, .collapsed = 2};

    int fileCount=15;
    for(int processingFileId=1;processingFileId<fileCount; processingFileId++){

    std::string sn=std::to_string(processingFileId);
    int rowId=0, colId=0; const char *groupTitle=sn.c_str(); //replace with filename without extesion
    worksheet_merge_range(worksheet, 0, grpColStart, 0, grpColEnd-1, groupTitle, merge_format);
    worksheet_set_row(worksheet, 0, LXW_DEF_ROW_HEIGHT, bold);

    for(rowId=1; rowId<40; rowId++)
    {
        for(colId=grpColStart; colId<grpColEnd; colId++)
        {
            worksheet_write_number(worksheet, rowId, colId, rowId*colId,  NULL);

        }
    }
    //rowId=0;colId=0;
    if(processingFileId==1 || processingFileId==fileCount){
            std::cout<<"Grp Sx : "<<grpColStart<<" Ex : "<<grpColEnd<<std::endl;
            worksheet_set_column_opt(worksheet, grpColStart, grpColEnd-2,  5, NULL, &col_options);

        }else{
        std::cout<<"Grp Sxm : "<<grpColStart<<" Exm : "<<grpColEnd<<std::endl;

        worksheet_set_column_opt(worksheet, grpColStart, grpColEnd-2,  5, NULL, &col_options);
       }
        grpColStart+=tcc;grpColEnd+=tcc;//processingFileId++;

    }

    workbook_close(workbook);
}


void Txt2Xcel ::  txt_2_xcel(std::list<std::list<std::string>> data_list, std::vector<int> col_list)
{
    /*lxw_workbook  */workbook  = workbook_new("Txt2Xcel.xlsx");
    /*lxw_worksheet */worksheet = workbook_add_worksheet(workbook, NULL);

    add_doc_properties();
    add_doc_cust_prop();

         int max_cols=col_list.size(), row_id=0, col_id=0;
         //std::cout<<"Col size : "<<max_cols<<std::endl;
         //std::cout<<"Data size : "<<dataList.size()<<std::endl;

        for(std::list<std::string> data : data_list)
        {

            for(std::string val : data)
            {
                /*for(int i=0; i<max_cols; i++)
                {
                    worksheet_write_string(worksheet, row_id, i, val.c_str(), NULL);
                }*/
                if(col_id==max_cols-1)
                    col_id=0;
                else
                    col_id++;

                worksheet_write_string(worksheet, row_id, col_id, val.c_str(), NULL);

            }
            row_id++;
            //std::cout<<std::endl;
        }
        //std::cout<<"----------------------------"<<std::endl;

    workbook_close(workbook);

}
