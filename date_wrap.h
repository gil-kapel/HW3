#ifndef DATE_WRAP_H
#define DATE_WRAP_H

#include "date.h"

   
class dateWrap{
    Date date; 
public:
    dateWrap(int day, int month, int year);
//*    ~dateWrap();
    int getDay(const dateWrap& date);
    int getMonth();
    int getYear();
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
};

dateWrap operator+(const dateWrap& date, int days);

#endif //DATE_WRAP_H_