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
    void add_doc_cust_prop(lxw_workbook *workbook);
    void add_doc_properties(lxw_workbook *wb);
    void createExcel();
    void txt_2_xcel(std::list<std::list<std::string>> data_list, std::vector<int> col_list);
    void createReport();
    ~Txt2Xcel();
};

#endif // TXT2XCEL_H
