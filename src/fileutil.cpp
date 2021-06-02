#include "fileutil.h"

FileUtil::FileUtil()
{

    /*fs::path p ("rdx");   // p reads clearer than argv[1] in the following code

    try
    {
      if (exists(p))    // does p actually exist?
      {
        if (is_regular_file(p))        // is p a regular file?
          std::cout << p << " size is " << file_size(p) << '\n';

        else if (is_directory(p))      // is p a directory?
        {
          std::cout << p << " is a directory containing:\n";

          copy(fs::directory_iterator(p), fs::directory_iterator(),  // directory_iterator::value_type
            std::ostream_iterator<fs::directory_entry>(std::cout, "\n"));  // is directory_entry, which is
                                                             // converted to a path by the
                                                             // path stream inserter
        }
        else
          std::cout << p << " exists, but is neither a regular file nor a directory\n";
      }
      else
        std::cout << p << " does not exist\n";
    }

    catch (const fs::filesystem_error& ex)
    {
      std::cout << ex.what() << '\n';
    }
*/

}

bool FileUtil :: is_file_exists(char *file_path)
{
    bool status=false;

    try
    {
        fs::path fp (file_path);   // p reads clearer than argv[1] in the following code

      if (exists(fp))    // does p actually exist?
      {
        if (is_regular_file(fp) && file_size(fp)>0)
            {
            status=true;
            // is p a regular file?
           //std::cout << fp << " size is " << file_size(fp) << '\n';
        }

        else if (is_directory(fp))      // is p a directory?
        {
//          std::cout << p << " is a directory containing:\n";
            status=false;
        }
        else{
            status=false;
        }
        //  std::cout << p << " exists, but is neither a regular file nor a directory\n";
      }
      else{
      status=false;
      }
       // std::cout << p << " does not exist\n";
    }

    catch (const fs::filesystem_error& ex)
    {
        status=false;
      std::cout << ex.what() << '\n';
    }

    return status;
}

void FileUtil ::  CxFs()
{
    fs::path aPath {"/rdx/tnt/fs.cpp"};

    std::cout << "Parent path: " << aPath.parent_path() << std::endl;
    std::cout << "Filename: " << aPath.filename() << std::endl;
    std::cout << "Extension: " << aPath.extension() << std::endl;

}
