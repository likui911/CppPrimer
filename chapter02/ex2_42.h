#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string.h>
#include <iostream>

struct Sales_data{
    std::string bookNo;
    unsigned unit_solds = 0;
    double revenue = 0;
};
#endif