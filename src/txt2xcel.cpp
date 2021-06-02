#include "txt2xcel.h"

Txt2Xcel::Txt2Xcel()
{

}

Txt2Xcel::~Txt2Xcel()
{

}

void Txt2Xcel :: add_doc_cust_prop(lxw_workbook *workbook)
{
    lxw_datetime   datetime  = {2021, 05, 12,  0, 0, 0.0};

    // Set some custom document properties in the workbook.
    workbook_set_custom_property_string  (workbook, "Checked by",      "Anjali Shah");
    workbook_set_custom_property_datetime(workbook, "Date completed",   &datetime);
    workbook_set_custom_property_number  (workbook, "Document number",  12345);
    workbook_set_custom_property_number  (workbook, "Reference number", 1.2345);
    workbook_set_custom_property_boolean (workbook, "Has Review",       1);
    workbook_set_custom_property_boolean (workbook, "Signed off",       0);

}

void Txt2Xcel :: add_doc_properties(lxw_workbook *wb)
{

    char _title[] =    "Report";
    char _subject[] =  "With the comment";
    char _author[]   = "Rajeev Rai";
    char _manager[]  = "R Rajeev";
    char _company[]  = "Rax Dev Team";
    char _category[] = "Report";
    char _keywords[] = "C, C++, Excel, Properties";
    char _comments[] = "Created with libxlsxwriter";
    char _status[]   = "Final";
    // Create a properties structure and set some of the fields.
    lxw_doc_properties doc_properties={
        .title = _title,
        .subject = _subject,
        .author=_author,
        .manager=_manager,
        .company=_company,
        .category=_category,
        .keywords=_keywords,
        .comments=_comments,
        .status=_status,
    };
    workbook_set_properties(wb, &doc_properties);

}



void Txt2Xcel :: createExcel()
{
    lxw_workbook  *workbook   = workbook_new("cold.xlsx");
    lxw_worksheet *worksheet3 = workbook_add_worksheet(workbook, "Outline Columns");

    /* Set the properties in the workbook. */
    add_doc_properties(workbook);
    add_doc_cust_prop(workbook);

    lxw_format *bold = workbook_add_format(workbook);
    format_set_bold(bold);

    lxw_format    *merge_format = workbook_add_format(workbook);

    /* Configure a format for the merged range. */
    format_set_align(merge_format, LXW_ALIGN_CENTER);
    format_set_align(merge_format, LXW_ALIGN_VERTICAL_CENTER);
    format_set_bold(merge_format);
    format_set_bg_color(merge_format, LXW_COLOR_YELLOW);
    format_set_border(merge_format, LXW_BORDER_THIN);

    /* Increase the cell size of the merged cells to highlight the formatting. */
    worksheet_set_column(worksheet3, 1, 3, 12, NULL);


    /*
     * Example 3: Create a worksheet with outlined columns.
     */
    lxw_row_col_options options6 = {.hidden = 0, .level = 1, .collapsed = 0};
    lxw_row_col_options options = {.hidden = 0, .level = 1, .collapsed = 0};

    /* Add data and formulas to the worksheet. */
    worksheet_write_string(worksheet3, CELL("A1"), "Month", NULL);
        /* Merge 3 cells. */
    worksheet_merge_range(worksheet3, 0, 0, 0, 2, "1", merge_format);

    worksheet_write_number(worksheet3, CELL("A2"), 25, NULL);
    worksheet_write_number(worksheet3, CELL("B2"), 50,      NULL);
    worksheet_write_number(worksheet3, CELL("C2"), 20,      NULL);

    worksheet_write_number(worksheet3, CELL("A3"), 15,  NULL);
    worksheet_write_number(worksheet3, CELL("B3"), 10,      NULL);
    worksheet_write_number(worksheet3, CELL("C3"), 20,      NULL);

    worksheet_write_number(worksheet3, CELL("A4"), 30,  NULL);
    worksheet_write_number(worksheet3, CELL("B4"), 45,      NULL);
    worksheet_write_number(worksheet3, CELL("C4"), 75,      NULL);

    /* Merge 3 cells. */
    worksheet_merge_range(worksheet3, 0, 4, 0, 6, "2", merge_format);

    worksheet_write_number(worksheet3, CELL("E2"), 5, NULL);
    worksheet_write_number(worksheet3, CELL("F2"), 10,      NULL);
    worksheet_write_number(worksheet3, CELL("G2"), 20,      NULL);

    worksheet_write_number(worksheet3, CELL("E3"), 6,  NULL);
    worksheet_write_number(worksheet3, CELL("F3"), 12,      NULL);
    worksheet_write_number(worksheet3, CELL("G3"), 24,      NULL);

    worksheet_write_number(worksheet3, CELL("E4"), 7,  NULL);
    worksheet_write_number(worksheet3, CELL("F4"), 14,      NULL);
    worksheet_write_number(worksheet3, CELL("G4"), 28,      NULL);

    /* Add bold format to the first row. */
    worksheet_set_row(worksheet3, 0, LXW_DEF_ROW_HEIGHT, bold);

    /* Set column formatting and the outline level. */
    //worksheet_set_column(    worksheet3, COLS("A:A"), 10, bold);
    worksheet_set_column_opt(worksheet3, COLS("B:C"),  5, NULL, &options6);
    worksheet_set_column_opt(worksheet3, COLS("D:F"),  5, NULL, &options);


    workbook_close(workbook);
}

void Txt2Xcel ::  createReport()
{
    lxw_workbook  *workbook  = workbook_new("report.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    lxw_chart *chart;
    lxw_chart_series *series;

    /* Write some data for the chart. */
    worksheet_write_number(worksheet, 0, 0, 10, NULL);
    worksheet_write_number(worksheet, 1, 0, 40, NULL);
    worksheet_write_number(worksheet, 2, 0, 50, NULL);
    worksheet_write_number(worksheet, 3, 0, 20, NULL);
    worksheet_write_number(worksheet, 4, 0, 10, NULL);
    worksheet_write_number(worksheet, 5, 0, 50, NULL);

    /* Create a chart object. */
    chart = workbook_add_chart(workbook, LXW_CHART_LINE);

    /* Configure the chart. */
    series = chart_add_series(chart, NULL, "Sheet1!$A$1:$A$6");

    (void)series; /* Do something with series in the real examples. */

    /* Insert the chart into the worksheet. */
    worksheet_insert_chart(worksheet, CELL("C1"), chart);

    workbook_close(workbook);

}

void Txt2Xcel ::  txt_2_xcel(std::list<std::list<std::string>> data_list, std::vector<int> col_list)
{
    lxw_workbook  *workbook  = workbook_new("Txt2Xcel.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    add_doc_properties(workbook);
    add_doc_cust_prop(workbook);

         int max_cols=col_list.size(), row_id=0, col_id=0;
         //std::cout<<"Col size : "<<max_cols<<std::endl;
         //std::cout<<"Data size : "<<dataList.size()<<std::endl;

        for(std::list<std::string> data : data_list)
        {

            for(std::string val : data)
            {
                /*for(int i=0; i<max_cols; i++)
                {
                    worksheet_write_string(worksheet, row_id, i, val.c_str(), NULL);
                }*/
                if(col_id==max_cols-1)
                    col_id=0;
                else
                    col_id++;

                worksheet_write_string(worksheet, row_id, col_id, val.c_str(), NULL);

            }
            row_id++;
            //std::cout<<std::endl;
        }
        //std::cout<<"----------------------------"<<std::endl;

    workbook_close(workbook);

}
