#include "date_wrap.h"
#include "date.h"
#include <iostream>
#include <stdbool.h>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;


dateWrap::dateWrap(int day, int month, int year)
{
    this->date = dateCreate(day, month, year);
}

int dateWrap::getDay(const dateWrap& date)
{
    int day, month, year;
    if(!dateGet(date.date, &day, &month, &year))
    {
        return 0;
    }
    return day;
}

int dateWrap::getMonth()
{
    int day, month, year;
    if(!dateGet(date, &day, &month, &year))
    {
        return 0;
    }
    return month;
}

int dateWrap::getYear()
{
    int day, month, year;
    if(!dateGet(date, &day, &month, &year))
    {
        return 0;
    }
    return year;
}

void dateWrap::printDate()
{
    int day, month, year;
    if(dateGet(date, &day, &month, &year))
    {
        cout << day << "/" << month << "/" << year << endl;
    }
}

bool dateWrap::operator==(const dateWrap& date)const
{
    if(dateCompare(this->date, date.date) == 0)
    {
        return true;
    }
    else return false;
}

bool dateWrap::operator>=(const dateWrap& date)const
{
    if(dateCompare(this->date, date.date) >= 0)
    {
        return true;
    }
    else return false;
}

bool dateWrap::operator<=(const dateWrap& date)const
{
    if(dateCompare(this->date, date.date) <= 0)
    {
        return true;
    }
    else return false;
}

bool dateWrap::operator!=(const dateWrap& date)const
{
    return !(this->operator==(date));
}

bool dateWrap::operator>(const dateWrap& date)const
{
    return !(this->operator<=(date));
}

bool dateWrap::operator<(const dateWrap& date)const
{
    return !(this->operator>=(date));
}

dateWrap&  dateWrap::operator++() //* ++date */
{
    dateTick(this->date);
}

dateWrap dateWrap::operator++(int) //* date++ */ 
{
    int day, month, year;
    dateGet(date, &day, &month, &year);
    dateWrap old_date(day, month, year);
    dateTick(this->date);
    return old_date;
}

dateWrap& dateWrap::operator+=(int days)
{
    while (days > 0)
	{
		dateTick(this->date);
		days = days--;
	}
	return *this;
}

dateWrap operator+(const dateWrap& date, int days)
{
    dateWrap new_date(dateWrap::getDay(date), dateWrap::getMonth(date), dateWrap::getYear(date));
    while (days > 0)
	{
        new_date++;
		days = days--;
	}
    return new_date;
}
