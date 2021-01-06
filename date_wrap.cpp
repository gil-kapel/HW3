#include "date_wrap.h"
#include "exceptions.h"
#include <iostream>
#include <stdbool.h>

#define MIN_DAY 1
#define MAX_DAY 30
#define MIN_MONTH 1
#define MAX_MONTH 12

using std::cout;
using std::cerr;
using std::cin;
using std::endl;



static bool isDateLegal(int day, int month)
{
    bool day_val = (day >= MIN_DAY) && (day <= MAX_DAY);
	bool month_val = (month >= MIN_MONTH) && (month <= MAX_MONTH);
    return ((day_val) && (month_val));
}

DateWrap::DateWrap(int day, int month, int year)
{
    if(isDateLegal(day,month))
    {
        this->date = dateCreate(day, month, year);
    }
    else mtm::InvalidDate();
}

DateWrap::~DateWrap()
{
    delete[] date;
}

DateWrap& DateWrap::operator=(const DateWrap& date)
{
    this->date = dateCopy(date.date);
}

int DateWrap::getDay(const DateWrap& date)
{
    int day, month, year;
    if(!dateGet(date.date, &day, &month, &year))
    {
        return 0;
    }
    return day;
}

int DateWrap::getMonth(const DateWrap& date)
{
    int day, month, year;
    if(!dateGet(date.date, &day, &month, &year))
    {
        return 0;
    }
    return month;
}

int DateWrap::getYear(const DateWrap& date)
{
    int day, month, year;
    if(!dateGet(date.date, &day, &month, &year))
    {
        return 0;
    }
    return year;
}

void DateWrap::printDate()
{
    int day, month, year;
    if(dateGet(date, &day, &month, &year))
    {
        cout << day << "/" << month << "/" << year << endl;
    }
}

bool DateWrap::operator==(const DateWrap& date)const
{
    if(dateCompare(this->date, date.date) == 0)
    {
        return true;
    }
    else return false;
}

bool DateWrap::operator>=(const DateWrap& date)const
{
    if(dateCompare(this->date, date.date) >= 0)
    {
        return true;
    }
    else return false;
}

bool DateWrap::operator<=(const DateWrap& date)const
{
    if(dateCompare(this->date, date.date) <= 0)
    {
        return true;
    }
    else return false;
}

bool DateWrap::operator!=(const DateWrap& date)const
{
    return !(this->operator==(date));
}

bool DateWrap::operator>(const DateWrap& date)const
{
    return !(this->operator<=(date));
}

bool DateWrap::operator<(const DateWrap& date)const
{
    return !(this->operator>=(date));
}

DateWrap&  DateWrap::operator++() //* ++date */
{
    dateTick(this->date);
    return *this;
}

DateWrap DateWrap::operator++(int) //* date++ */ 
{
    int day, month, year;
    dateGet(date, &day, &month, &year);
    DateWrap old_date(day, month, year);
    dateTick(this->date);
    return old_date;
}

DateWrap& DateWrap::operator+=(int days)
{
    while (days > 0)
	{
		++(*this);
		--days;
	}
	return *this;
}

DateWrap operator+(const DateWrap& date, int days)
{
    int day, month, year;
    dateGet(date.date, &day, &month, &year);
    return DateWrap(day, month, year) += days;
}

DateWrap operator+(int days, const DateWrap& date)
{
    int day, month, year;
    dateGet(date.date, &day, &month, &year);
    return DateWrap(day, month, year) += days;
}
