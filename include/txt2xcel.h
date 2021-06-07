#ifndef TXT2XCEL_H
#define TXT2XCEL_H

#include <xlsxwriter.h>
#include <list>
#include <vector>
#include <string>
#include <iostream>

class Txt2Xcel
{
public:
    Txt2Xcel();
    Txt2Xcel(std::string _dirPath, std::string _fileName, int _skipRowNo, std::list<int> _col, std::string _colSeparator);
    Txt2Xcel(std::string _dirPath,  std::string _fileName,  std::string _fileExtension, int _skipRowNo, std::list<int> _col, int _colDif, std::string _colSeparator);
    Txt2Xcel(std::string _dirPath, std::string _fileName, int _skipRowNo, std::list<int> _col, int _colDif, std::string _colSeparator);
    std::list<std::list<double>> parseTextFile(std::string _filename);

    void wxExData2ManyEx();
    void wxExData2ManySx();
    void wxExData2OneEx();
    void wxExData2OneSx();
    void writeExcelData(std::string _title, std::list<std::list<double>> &_dataList);
    void writeExcelData(std::vector<std::vector<double>> &_dataList);

    void createExcel();
    void txt_2_xcel(std::list<std::list<std::string>> data_list, std::vector<int> col_list);
    //void createReport();
    ~Txt2Xcel();
private:
    void init_excel_file();
    void add_doc_cust_prop(/*lxw_workbook *workbook*/);
    void add_doc_properties(/*lxw_workbook *wb*/);
    void writeFile(std::string _filename, std::list<std::list<double>> _dataList);
    std::string readFile(std::string _filename);
    void fileNamePathListNumbX();
    void fileNamePathList();

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
    std::vector<std::vector<int>> cellRange;
    std::vector<std::string> filePathList;
    std::string colSeparator;
    std::string dirPath;
    std::string fileName;
    std::string fileExtension;
};

#endif // TXT2XCEL_H
