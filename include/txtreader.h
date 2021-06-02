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

    /*TxtReader(std::string _filename, std::string _delimeter = ",") :
              filename(_filename), delimeter(_delimeter)
    { }
    TxtReader(std::string _filename, int _skipRow, std::string _sel_cols, std::string _delimeter = ",") :
              filename(_filename), skipRow(_skipRow), sel_cols(_sel_cols), delimeter(_delimeter)
    { }*/

    // Function to fetch data from a CSV File
    std::vector<int> sel_cols_list(std::string cols);
    std::vector<std::vector<std::string> > getData();
    std::vector<std::vector<std::string> > getData(int skipRow);
    std::list<std::list<std::string>> getNumericalData();
    std::list<std::list<std::string>> getNumericalData(int skipRow);
    std::list<std::list<std::string>> getNumericalData(std::string _filename, int _skipRow, std::string _sel_cols, int _del_type);
    std::list<std::list<std::string>> getNumericalData(std::string _filename, int _skipRow, std::string _sel_cols, std::string custom_delimeter);

    ~TxtReader();
};

#endif // TXTREADER_H
