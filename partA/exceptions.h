#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
#include <exception>

namespace mtm{
    class Exception : public std::exception{};

    class InvalidDate : public Exception{};

    class NegativeDays : public Exception{};

    class NotRegistered : public Exception{};
    
    class InvalidStudent : public Exception{};
    
    class FullList : public Exception{};
    
    class AlreadyRegistered : public Exception{};
    
    class AlreadyInvited : public Exception{};

    class RegistrationBlocked : public Exception{};

    class NotSupported : public Exception{};
    
    class DateMismatch : public Exception{};

    class InvalidNumber : public Exception{};

    class InvalidInterval : public Exception{};

    class EventAlreadyExists : public Exception{};

    class EventDoesNotExist : public Exception{};

} //* End of mtm namespace */

#endif //EXCEPTIONS_H_