#include "txtreader.h"

TxtReader::TxtReader()
{

}

TxtReader::~TxtReader()
{

}

std::vector<int> TxtReader :: sel_col_index_vect(std::string cols)
{
    std::string defdelim=",";
    std::vector<int> col;
    std::stringstream s_stream(cols); //create string stream from the string
    //int sum=0,i=0;
    while(s_stream.good()){
        std::string colId;
        std::getline(s_stream, colId, ','); //get first string delimited by comma
        col.push_back(atoi(colId.c_str()));
        //sum+=col[i];i++;
        //std::cout<<" "<<colId;
    }
    //std::cout<<"\nSum : "<<sum<<std::endl;

    return col;
}

std::list<int> TxtReader :: sel_col_index_list(std::string cols)
{
    std::string defdelim=",";
    std::list<int> col;
    std::stringstream s_stream(cols); //create string stream from the string
    //int sum=0,i=0;
    while(s_stream.good()){
        std::string colId;
        std::getline(s_stream, colId, ','); //get first string delimited by comma
        col.push_back(atoi(colId.c_str()));
        //sum+=col[i];i++;
        //std::cout<<" "<<colId;
    }
    //std::cout<<"\nSum : "<<sum<<std::endl;

    return col;
}

std::vector<std::vector<std::string>> TxtReader::getData()
{
    std::ifstream file(filename);
    std::vector<std::vector<std::string> > dataList;
    std::string line = "";
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter[delim_type]));
        dataList.push_back(vec);
    }
    // Close the File
    file.close();
    return dataList;
}

std::vector<std::vector<std::string>> TxtReader::getData(int skipRow)
{
    std::ifstream file(filename);
    std::vector<std::vector<std::string> > dataList;
    std::string line = "";
    // Iterate through each line and split the content using delimeter
    long lineNumber=0;
    while (getline(file, line))
    {
        if(lineNumber>skipRow)
        {
            lineNumber++;
            std::vector<std::string> vec;
            boost::algorithm::split(vec, line, boost::is_any_of(delimeter[delim_type]));
            dataList.push_back(vec);
        }

    }
    // Close the File
    file.close();
    return dataList;
}


std::list<std::list<std::string>> TxtReader::getNumericalData()
{
    std::ifstream file(filename);
    std::list<std::list<std::string>> dataList;
    std::string line = "";
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        std::list<std::string> data;
        boost::algorithm::split(data, line, boost::is_any_of(delimeter[delim_type]));
        dataList.push_back(data);
    }
    // Close the File
    file.close();
    return dataList;
}

std::list<std::list<std::string>> TxtReader::getNumericalData(int skipRow)
{
    std::ifstream file(filename);
    std::list<std::list<std::string>> dataList;
    std::string line = "";
    long lineNumber=0;
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        if(lineNumber>=skipRow)
        {
            std::list<std::string> data;
            boost::algorithm::split(data, line, boost::is_any_of(delimeter[delim_type]));
            dataList.push_back(data);
        }
        lineNumber++;

    }
    // Close the File
    file.close();
    return dataList;
}

std::list<std::list<std::string>> TxtReader::getNumericalData(std::string _filename, int _skipRow, std::string _sel_cols, int _delim_type)
{
    std::ifstream file(_filename);
    std::list<std::list<std::string>> dataList;
    std::string line = "";
    long lineNumber=0;
    std::vector<int>  cols = sel_col_index_vect(_sel_cols);
    int col_count=cols.size();

    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        if(lineNumber>=_skipRow)
        {
            std::vector<std::string> data;
            boost::algorithm::split(data, line, boost::is_any_of(delimeter[_delim_type]));
            std::list<std::string> sdata;
            for(int i=0; i<col_count; i++)
            {
                sdata.push_back(data[cols[i]]);
            }
            dataList.push_back(sdata);
        }
        lineNumber++;

    }
    // Close the File
    file.close();
    return dataList;
}

std::list<std::list<std::string>> TxtReader::getNumericalData(std::string _filename, int _skipRow, std::string _sel_cols, std::string custom_delimeter)
{
    std::ifstream file(_filename);
    std::list<std::list<std::string>> dataList;
    std::string line = "";
    long lineNumber=0;
    std::vector<int>  cols = sel_col_index_vect(_sel_cols);
    int col_count=cols.size();
    //std::cout<<"XXX : "<<custom_delimeter<<std::endl;
    /*if(_delim_type>2)
    {
        delimeter[3]=custom_delimeter;

    }*/
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        if(lineNumber>=_skipRow)
        {
            std::vector<std::string> data;
            boost::algorithm::split(data, line, boost::is_any_of(custom_delimeter));
            std::list<std::string> sdata;
            for(int i=0; i<col_count; i++)
            {
                sdata.push_back(data[cols[i]]);
            }
            dataList.push_back(sdata);
        }
        lineNumber++;

    }
    // Close the File
    file.close();
    return dataList;
}

std::list<std::list<double>> TxtReader ::  parseTxt2Number_LIST(std::string _filename, int _skipRow, std::string _sel_cols, int _del_type)
{
    std::ifstream file(_filename);
    std::list<std::list<double>> dataList;
    std::string line = "";
    long lineNumber=0;
    std::vector<int>  cols = sel_col_index_vect(_sel_cols);
    int col_count=cols.size();
    //std::cout<<"XXX : "<<custom_delimeter<<std::endl;
    /*if(_delim_type>2)
    {
        delimeter[3]=custom_delimeter;

    }*/
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        if(lineNumber>=_skipRow)
        {
            std::vector<std::string> data;
            boost::algorithm::split(data, line, boost::is_any_of(delimeter[_del_type]));
            std::list<double> ndata;
            for(int i=0; i<col_count; i++)
            {
                ndata.push_back(atof(data[cols[i]].c_str()));
            }
            dataList.push_back(ndata);
        }
        lineNumber++;

    }
    // Close the File
    file.close();
    return dataList;
}

std::vector<std::vector<double>> TxtReader ::  parseTxt2Number_VECT(std::string _filename, int _skipRow, std::string _sel_cols, int _del_type)
{
    std::ifstream file(_filename);
    std::vector<std::vector<double>> dataList;
    std::string line = "";
    long lineNumber=0;
    std::vector<int>  cols = sel_col_index_vect(_sel_cols);
    int col_count=cols.size();
    //std::cout<<"XXX : "<<custom_delimeter<<std::endl;
    /*if(_delim_type>2)
    {
        delimeter[3]=custom_delimeter;

    }*/
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        if(lineNumber>=_skipRow)
        {
            std::vector<std::string> data;
            boost::algorithm::split(data, line, boost::is_any_of(delimeter[_del_type]));
            std::vector<double> ndata;
            for(int i=0; i<col_count; i++)
            {
                ndata.push_back(atof(data[cols[i]].c_str()));
            }
            dataList.push_back(ndata);
        }
        lineNumber++;

    }
    // Close the File
    file.close();
    return dataList;
}

