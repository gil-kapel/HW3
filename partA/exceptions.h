#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
#include <exception>
using std::exception;

namespace mtm{
    class Exception : public std::exception{};

    class InvalidDate : public Exception{};

    class NegativeDays : public Exception{};

    class NotRegistered : public Exception{};
    
    class InvalidMember : public Exception{};
    
    class FullList : public Exception{};
    
    class AlreadyRegistered : public Exception{};
    
    class AlreadyInvited : public Exception{};

    class RegistrationBlocked : public Exception{};

    class NotSupported : public Exception{};
        
    class DateMismatch : public Exception{};

    class InvalidNumber : public Exception{};

    class EventAlreadyExists : public Exception{};

    class EventDoesNotExist : public Exception{};

} //* End of mtm namespace */

#endif //EXCEPTIONS_H_