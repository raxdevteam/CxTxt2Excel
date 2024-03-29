#include "consoleprint.h"

void ConsolePrint :: print_txt_file_data(int max_cols, std::list<std::list<std::string>> dataList)
{
    std::cout<<"Printing data..."<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
        // Print the content of row by row on screen
         int col_i=1;
         std::cout<<"Col size : "<<max_cols<<std::endl;
         std::cout<<"Data size : "<<dataList.size()<<std::endl;
         std::cout<<"----------------------------"<<std::endl;

        for(std::list<std::string> data : dataList)
        {
                //std::cout<<data<<" , "<<data[1]<<" , "<<data[2];
            for(std::string val : data)
            {
                //if(col_i==colList[col_i]){
                    if(col_i==max_cols)
                    {
                       std::cout<<val;
                       col_i=1;
                    }

                    else{
                        std::cout<<val<<" , ";
                        col_i++;
                    }
                //}
            }
            std::cout<<std::endl;
        }
        std::cout<<"----------------------------"<<std::endl;
}

void ConsolePrint :: print_txt_file_data_vect(int max_cols, std::vector<std::vector<double>> dataList)
{
    std::cout<<"Printing data..."<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
        // Print the content of row by row on screen
        // int col_i=1;
         std::cout<<"Col size : "<<max_cols<<std::endl;
         std::cout<<"Data size : "<<dataList.size()<<std::endl;
         std::cout<<"----------------------------"<<std::endl;

         for(std::vector<double> dataCol : dataList)
         {
             for(int i=0;i<max_cols;i++)
             {
                 if(i==max_cols-1)
                   std::cout<<dataCol[i];
                 else
                   std::cout<<dataCol[i]<<" ";
             }
         }


        /*for(std::list<std::string> data : dataList)
        {
                //std::cout<<data<<" , "<<data[1]<<" , "<<data[2];
            for(std::string val : data)
            {
                //if(col_i==colList[col_i]){
                    if(col_i==max_cols)
                    {
                       std::cout<<val;
                       col_i=1;
                    }

                    else{
                        std::cout<<val<<" , ";
                        col_i++;
                    }
                //}
            }
            std::cout<<std::endl;
        }*/
        std::cout<<"----------------------------"<<std::endl;
}


/* std::vector<std::vector<std::string> > dataList = reader.getData();
// Print the content of row by row on screen
//int sel_col [] = {1,2};
std::vector<int> sel_col=reader.sel_cols("1,2");
// Print the content of row by row on screen
int max_cols=4, max_sel_col=sel_col.size();

for(std::vector<std::string> vec : dataList)
{
    //for(std::string data : vec)
   // {
        for(int i=0; i<max_sel_col; i++)
        {
            std::cout<<vec[sel_col[i]]<<" , ";
        }
        //std::cout<<data << " , ";
        //if(col_i==sel_col[col_i]){
            /if(col_i==max_cols)
            {
               std::cout<<data;
               col_i=1;
            }

            else{
                std::cout<<data<<" , ";
                col_i++;
            }
   //     }


  //  }
    std::cout<<std::endl;
}*/

/*if (argc < 2)
{
cout << "Usage: tut3 path\n";
return 1;
}

//argv[1]="include";
*/

