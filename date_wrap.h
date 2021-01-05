#ifndef DATE_WRAP_H
#define DATE_WRAP_H

#include <>
#include "date.h"

   
class dateWrap{
    int day;
    int week;
    int year;
public:
    dateWrap(Date date);
//*    ~dateWrap();
    int getDay();
    int getMonth();
    int getYear();
    void printDate();
    bool operator==(const dateWrap& date)const;
    bool operator>=(const dateWrap& date);
    bool operator<=(const dateWrap& date);
    bool operator!=(const dateWrap& date);
    bool operator>(const dateWrap& date);
    bool operator<(const dateWrap& date);
    dateWrap& operator++();
    dateWrap& operator+=(int days);
}

dateWrap operator+(int days);
