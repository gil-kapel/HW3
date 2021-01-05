#include "date_wrap.h"
#include "date.h"
#include <iostream>
#include <stdbool.h>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;


dateWrap::dateWrap(Date date)
{
    dateGet(date, &day, &week, &year);
}

dateWrap::getDay()
{
    return day;
}

dateWrap::getMonth()
{
    return this->month;
}

dateWrap::getYear()
{
    return this->year;
}

dateWrap::printDate()
{
    cout << this->day << "/" << this->week << "/" << this year << endl;
}

bool dateWrap::operator==(const dateWrap& date)
{
    if(dateCompare(this, date) == 0)
    {
        return true;
    }
    else return false;
}

bool dateWrap::operator>=(const dateWrap& date)
{
    if(dateCompare(this, date) >= 0)
    {
        return true;
    }
    else return false;
}

bool dateWrap::operator<=(const dateWrap& date)
{
    if(dateCompare(this, date) <= 0)
    {
        return true;
    }
    else return false;
}

bool dateWrap::operator!=(const dateWrap& date)
{
    if(this == date)
    {
        return false;
    }
    else return true;
}

bool dateWrap::operator>(const dateWrap& date)
{
    if(this <= date)
    {
        return false;
    }
    else return true;
}

bool dateWrap::operator<(const dateWrap& date)
{
    if(this >= date)
    {
        return false;
    }
    else return true;
}

dateWrap::dateWrap& operator++()
{
    dateTick(this);
}

dateWrap::dateWrap& operator+=(int days)
{
    while (days > 0)
	{
		dateTick(this);
		days = days--;
	}
	return *this;
}

dateWrap operator+(int days)
{
    dateWrap date(this->day, this->week, this->year);
    while (days > 0)
	{
		dateTick(&date);
		days = days--;
	}
}
