#ifndef TXTREADER_H
#define TXTREADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <boost/algorithm/string.hpp>

class TxtReader
{
private:
    std::string filename;
    std::string sel_cols;
    int skipRow;
    int delim_type;
    std::string delimeter[3]={",", "\t", " "};

public:
    TxtReader();

    // Function to fetch data from a CSV File
    static std::vector<int> sel_col_index_vect(std::string cols);
    static std::list<int> sel_col_index_list(std::string cols);
    std::vector<std::vector<std::string> > getData();
    std::vector<std::vector<std::string> > getData(int skipRow);
    std::list<std::list<std::string>> getNumericalData();
    std::list<std::list<std::string>> getNumericalData(int skipRow);
    std::list<std::list<double>> parseTxt2Number_LIST(std::string _filename, int _skipRow, std::string _sel_cols, int _del_type);
    std::list<std::list<std::string>> getNumericalData(std::string _filename, int _skipRow, std::string _sel_cols, int _del_type);
    std::list<std::list<std::string>> getNumericalData(std::string _filename, int _skipRow, std::string _sel_cols, std::string custom_delimeter);
    std::vector<std::vector<double>> parseTxt2Number_VECT(std::string _filename, int _skipRow, std::string _sel_cols, int _del_type);

    ~TxtReader();
};

#endif // TXTREADER_H
