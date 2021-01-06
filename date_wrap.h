#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_

extern "C"
{
    #include "date.h"
}

class DateWrap{
    Date date; 
public:
    DateWrap(int day = 1, int month = 1, int year = 2021);
    ~DateWrap();
    int getDay(const DateWrap& date);
    int getMonth(const DateWrap& date);
    int getYear(const DateWrap& date);
    void printDate();
    bool operator==(const DateWrap& date)const;
    bool operator>=(const DateWrap& date)const;
    bool operator<=(const DateWrap& date)const;
    bool operator!=(const DateWrap& date)const;
    bool operator>(const DateWrap& date)const;
    bool operator<(const DateWrap& date)const;
    DateWrap& operator++();
    DateWrap operator++(int);
    DateWrap& operator+=(int days);
    friend DateWrap operator+(const DateWrap& date, int days);
    friend DateWrap operator+(int days, const DateWrap& date);
};

DateWrap operator+(const DateWrap& date, int days);

DateWrap operator+(int days, const DateWrap& date);

#endif //DATE_WRAP_H_