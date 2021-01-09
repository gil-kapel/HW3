#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_

#define MIN_DAY 1
#define MAX_DAY 30
#define MIN_MONTH 1
#define MAX_MONTH 12

extern "C"
{
    #include "date.h"
}

namespace mtm{
    
    class DateWrap{
        Date date; 
    public:
        void isDateValid(int day, int month)const;
        DateWrap(int day, int month, int year);
        ~DateWrap();
        DateWrap& operator=(const DateWrap& date);
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
        DateWrap& operator++(); //* not needed duo to the instratcions */
        DateWrap operator++(int);
        DateWrap& operator+=(int days);
    }; //* End of DateWrap class */

    DateWrap operator+(const DateWrap& date, int days);

    DateWrap operator+(int days, const DateWrap& date);

} //End of mtm namespace*/

#endif //DATE_WRAP_H_