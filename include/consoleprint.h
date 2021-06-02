#ifndef CONSOLEPRINT_H
#define CONSOLEPRINT_H

#include<list>
#include<iostream>

class ConsolePrint
{
public:
    ConsolePrint();
    static void print_txt_file_data(int max_cols, std::list<std::list<std::string>> dataList);
    void print_xml_file_data(int max_cols, std::list<std::list<std::string>> dataList);
    void print_json_file_data(int max_cols, std::list<std::list<std::string>> dataList);

};

#endif // CONSOLEPRINT_H
