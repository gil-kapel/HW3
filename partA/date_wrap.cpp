#include "date_wrap.h"
#include "exceptions.h"
#include <iostream>
#include <stdbool.h>

using mtm::DateWrap;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;


DateWrap::DateWrap(int day, int month, int year)
{
    if((month < MIN_MONTH) || (month > MAX_MONTH) || (day < MIN_DAY) || (day > MAX_DAY))
    {
        throw mtm::InvalidDate();
    }
    date = dateCreate(day, month, year);
}

DateWrap::DateWrap(const DateWrap& new_date):
    date(dateCopy(new_date.date)){
}

DateWrap::~DateWrap()
{
    dateDestroy(date);
}

DateWrap& DateWrap::operator=(const DateWrap& date)
{
    if(this == &date)
    {
        return *this;
    }
    dateDestroy(this->date);
    this->date = dateCopy(date.date);
    return *this;
}

int DateWrap::day() 
{
    int day, month, year;
    DateWrap temp_date = *this;
    if(!dateGet(temp_date.date, &day, &month, &year))
    {
        return 0;
    }
    return day;
}

int DateWrap::month() 
{
    int day, month, year;
    DateWrap temp_date(*this);
    if(!dateGet(temp_date.date, &day, &month, &year))
    {
        return 0;
    }
    return month;
}

int DateWrap::year() 
{
    int day, month, year;
    DateWrap temp_date(*this);
    if(!dateGet(temp_date.date, &day, &month, &year))
    {
        return 0;
    }
    return year;
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
    if(days < 0)
    {
        throw mtm::NegativeDays();
    }
    while (days > 0)
	{
		(*this)++;
		days--;
	}
	return *this;
}

DateWrap mtm::operator+(const DateWrap& date, int days)
{
    if(days < 0)
    {
        throw mtm::NegativeDays();
    }
    DateWrap new_date = date;
    return new_date += days;
}

DateWrap mtm::operator+(int days, const DateWrap& date)
{
    if(days < 0)
    {
        throw mtm::NegativeDays();
    }
    DateWrap new_date = date;
    return new_date += days;
}

ostream& mtm::operator<<(ostream& os, const DateWrap& date)
{
    DateWrap new_date(date);
    return os << new_date.day() << "/" << new_date.month() << "/" << new_date.year();
}