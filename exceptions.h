#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
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

    class NotRegistered : public Exception{
    public:
        NotRegistered() = default;
    };
    
    class InvalidMember : public Exception{
    public:
        InvalidMember() = default;
    };
    
    class FullList : public Exception{
    public:
        FullList() = default;
    };
    
    class AlreadyRegistered : public Exception{
    public:
        AlreadyRegistered() = default;
    };
    
} //* End of mtm namespace */

#endif //EXCEPTIONS_H_