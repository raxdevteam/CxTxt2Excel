#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <experimental/filesystem>
#include <iostream>
#include <iterator>
#include <algorithm>

namespace fs = std::experimental::filesystem;

class FileUtil
{
public:
    FileUtil();
    bool is_file_exists(char *file_path);
    void CxFs();
};

#endif // FILEUTIL_H
