#ifndef DATE_WRAP_H
#define DATE_WRAP_H

#include "date.h"

   
class dateWrap{
    Date date; 
public:
    dateWrap(int day = 1, int month = 1, int year = 2021);
//*    ~dateWrap();
    int getDay();
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
    dateWrap operator+(int days);

};


#endif //DATE_WRAP_H_