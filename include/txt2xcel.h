#ifndef TXT2XCEL_H
#define TXT2XCEL_H

#include <xlsxwriter.h>
#include <time.h>
/*#include <list>
#include <vector>
#include <string>
#include <iostream>
*/
#include "fileutil.h"
#include "txtreader.h"
#include "consoleprint.h"

class Txt2Xcel
{
public:
    Txt2Xcel();
    Txt2Xcel(std::string _fileName, int _skipRowNo, std::string _cols, int _colSeparatorType);
    Txt2Xcel(std::string _fileName, int _skipRowNo, std::string _cols, int _colDif, int _colSeparatorType);
    Txt2Xcel(int opt, std::string _fileName, int _skipRowNo, std::string _cols, int _colSeparatorType);
    void wx_mfx_2_msx();
    void wx_of_2_ex();
    void wx_mfx_2_mex();
    //Write many file to one sheet
    void wx_mfx_2_one_sx(/*std::string _file_name*/);

    void write_excel_data(std::string title, std::vector<std::vector<double>> _dataRowList);
    void txt_2_xcel(std::list<std::list<std::string>> data_list, std::vector<int> col_list);
    ~Txt2Xcel();
private:
    char* get_filename_timeStamp();
    void add_doc_cust_prop();
    void add_doc_properties();

private:
    lxw_workbook  *workbook;
    lxw_worksheet *worksheet;
    lxw_format *bold;
    lxw_format    *merge_format;
    lxw_row_col_options col_options;
    lxw_doc_properties doc_properties;

    int grpColStart;
    int grpColEnd;
    int grpColEndtcc;
    int tcc;
    int colDif;
    int fileCount;
    int row;
    int colCount;
    int processingFileId;
    int skipRowNo;
    std::list<int> col;
    std::string cols;
    std::vector<std::vector<int>> cellRange;
    std::vector<std::string> filePathList;
    int colSeparatorType;
    std::string dirPath;
    std::string fileName;
    std::string fileExtension;
};

#endif // TXT2XCEL_H
