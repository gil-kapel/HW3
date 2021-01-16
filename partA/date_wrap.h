#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_

#include <iostream>

#define MIN_DAY 1
#define MAX_DAY 30
#define MIN_MONTH 1
#define MAX_MONTH 12

extern "C"
{
    #include "date.h"
}
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;


namespace mtm{
    class DateWrap{
        Date date; 
    public:
        void isDateValid(int day, int month)const;
        DateWrap(int day, int month, int year);
        ~DateWrap();
        DateWrap& operator=(const DateWrap& date);
        int getDay(const DateWrap& date) const;
        int getMonth(const DateWrap& date) const;
        int getYear(const DateWrap& date) const;
        bool operator==(const DateWrap& date)const;
        bool operator>=(const DateWrap& date)const;
        bool operator<=(const DateWrap& date)const;
        bool operator!=(const DateWrap& date)const;
        bool operator>(const DateWrap& date)const;
        bool operator<(const DateWrap& date)const;
        DateWrap operator++(int);
        DateWrap& operator+=(int days);
        friend ostream& operator<<(ostream& os, const DateWrap& date);
    }; //* End of DateWrap class */

    DateWrap operator+(const DateWrap& date, int days);

    DateWrap operator+(int days, const DateWrap& date);

    ostream& operator<<(ostream& os, const DateWrap& date)
    {
        return os << date.getDay(date) << "/" << date.getMonth(date) << "/" << date.getYear(date) << endl;
    }

} //End of mtm namespace*/


#endif //DATE_WRAP_H_