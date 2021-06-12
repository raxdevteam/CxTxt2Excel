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

std::list<std::string> FileUtil :: show_file_path(std::string fileExtension)
{
    std::list<std::string> filePathList;
    std::string path = fs::current_path();
    std::cout<<"Current path : "<<path<<std::endl;
    fs::path aPath{path};
    std::cout << "Parent path: " << aPath.parent_path() << std::endl;

        for (const auto & entry : fs::directory_iterator(path))
        {
         fs::path file{entry.path()};
         //std::cout<<"Relative path : "<<file.relative_path()<<std::endl;

          if(fs::is_regular_file(file) && file.extension().compare(fileExtension)==0)
          {
         // std::cout << file.filename() << file.extension() << std::endl;

          filePathList.push_back(file.relative_path());//file.filename());
          }
        }
        filePathList.sort();
    return filePathList;
}

std::list<std::string> FileUtil :: read_directory_file_path(std::string _file_name)
{
    fs::path file_path{_file_name};
    std::cout<<"Current path : "<<fs::current_path()<<std::endl;
    std::cout << "Parent path: " << file_path.parent_path() << std::endl;
    std::cout << "File path: " << file_path.relative_path() << std::endl;
    std::string file_extension=file_path.extension();
    std::cout<<"Extension : "<<file_extension<<std::endl;
    std::cout << "File Cx path: " << file_path.remove_filename() << std::endl;

    std::list<std::string> filePathList;
        for (const auto & entry : fs::directory_iterator(file_path))
        {
         fs::path file{entry.path()};
         //std::cout<<"Relative path : "<<file.relative_path()<<std::endl;

          if(fs::is_regular_file(file) && file.extension().compare(file_extension)==0)
          {
         // std::cout << file.filename() << file.extension() << std::endl;

          filePathList.push_back(file.relative_path());//file.filename());
          }
        }
        filePathList.sort();
    return filePathList;
}


std::vector<std::string> FileUtil :: get_file_name_list_without_extension(std::string _file_name)
{
    std::vector<std::string> file_name_List;
    std::list<std::string> file_list=read_directory_file_path(_file_name);
    for(std::string file_name_path : file_list)
    {
        fs::path file{file_name_path};
        file.replace_extension("");//remove extension
        file_name_List.push_back(file.filename());
        std::cout<<"File title : "<<file.filename()<<std::endl;
    }
    return file_name_List;
}

std::string FileUtil :: get_file_directory(std::string file_name)
{
     fs::path file {file_name};
     if(exists(file) && fs::is_regular_file(file) && !is_directory(file))
     {
         std::string file_path=file.relative_path().remove_filename();
         std::cout<<"File path : "<<file_path<<std::endl;
         return file_path;
     }else{
         std::cout<<"Invalid File Name"<<std::endl;
         return "IFP";//Invalid file path
     }

}
