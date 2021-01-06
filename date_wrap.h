#ifndef DATE_WRAP_H
#define DATE_WRAP_H

#include "date.h"

   
class dateWrap{
    Date date; 
public:
    dateWrap(int day = 1, int month = 1, int year = 2021);
    ~dateWrap();
    int getDay(const dateWrap& date);
    int getMonth(const dateWrap& date);
    int getYear(const dateWrap& date);
    void printDate();
    bool operator==(const dateWrap& date)const;
    bool operator>=(const dateWrap& date)const;
    bool operator<=(const dateWrap& date)const;
    bool operator!=(const dateWrap& date)const;
    bool operator>(const dateWrap& date)const;
    bool operator<(const dateWrap& date)const;
    dateWrap& operator++();
    dateWrap operator++(int);
    dateWrap& operator+=(int days);
    friend dateWrap operator+(const dateWrap& date, int days);
};

dateWrap operator+(const dateWrap& date, int days);

#endif //DATE_WRAP_H_