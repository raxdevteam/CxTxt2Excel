#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <experimental/filesystem>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <vector>
#include <string>

namespace fs = std::experimental::filesystem;

class FileUtil
{
public:
    static bool is_file_exists(char *file_path);
    static std::list<std::string> show_file_path(std::string fileExtension);
    static std::string get_file_directory(std::string file_name);
    static std::list<std::string> read_directory_file_path(std::string _file_name);
    static std::vector<std::string> get_file_name_list_without_extension(std::string _file_name);

};

#endif // FILEUTIL_H
