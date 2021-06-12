#ifndef TXT2XCEL_H
#define TXT2XCEL_H

#include <xlsxwriter.h>
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
    Txt2Xcel(std::string _dirPath, std::string _fileName, int _skipRowNo, std::list<int> _col, int _colSeparatorType);
    Txt2Xcel(std::string _fileName, int _skipRowNo, std::string _cols, int _colDif, int _colSeparatorType);
    Txt2Xcel(std::string _dirPath, std::string _fileName, int _skipRowNo, std::list<int> _col, int _colDif, int _colSeparatorType);

    void wxExData2ManyEx();
    void wxExData2ManySx();
    void wxExData2OneEx();
    //Write many file to one sheet
    void wx_mfx_2_one_sx(/*std::string _file_name*/);
    void writeExcelData(std::string _title, std::list<std::list<double>> &_dataList);
    //void writeExcelData(std::vector<std::vector<double>> &_dataList);

    void write_excel_data(std::string title, std::vector<std::vector<double>> _dataRowList);
    void txt_2_xcel(std::list<std::list<std::string>> data_list, std::vector<int> col_list);
    //void createReport();
    ~Txt2Xcel();
private:
    void init_excel_file();
    void add_doc_cust_prop(/*lxw_workbook *workbook*/);
    void add_doc_properties(/*lxw_workbook *wb*/);
    std::list<std::list<double>> parseTextFile(std::string _filename);

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
