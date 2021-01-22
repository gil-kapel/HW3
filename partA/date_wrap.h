#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_

#include <iostream>
extern "C"
{
    #include "../provided/date.h"
}
#include "exceptions.h"
namespace mtm{
    class DateWrap{
        Date date; 
    public:
        DateWrap(int day, int month, int year);
        DateWrap(const DateWrap& new_date); 
        ~DateWrap();
        DateWrap& operator=(const DateWrap& date);
        int day();
        int month();
        int year();
        bool operator==(const DateWrap& date)const; //only comapre between two date classes
        bool operator>=(const DateWrap& date)const;
        bool operator<=(const DateWrap& date)const;
        bool operator!=(const DateWrap& date)const;
        bool operator>(const DateWrap& date)const;
        bool operator<(const DateWrap& date)const;
        DateWrap operator++(int); // forword one day
        DateWrap& operator+=(int days); // forword "days" for the date day
        friend std::ostream& operator<<(std::ostream& os, const DateWrap& date);
    }; //* End of DateWrap class */

    DateWrap operator+(const DateWrap& date, int days);

    DateWrap operator+(int days, const DateWrap& date);

    std::ostream& operator<<(std::ostream& os, const DateWrap& date);

} //End of mtm namespace*/


#endif //DATE_WRAP_H_