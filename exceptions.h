#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>

using std::exception;

namespace mtm{
    class Exception : public std::exception{
    };

    class InvalidDate : public Exception{
    public:
        InvalidDate() = default;
    };

    class NegativeDays : public Exception{
    public:
        NegativeDays() = default;
    };

} //* End of mtm namespace */

#endif //EXCEPTIONS_H_