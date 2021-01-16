#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
#include <exception>
using std::exception;

namespace mtm{
    class Exception : public std::exception{
    };

    class InvalidDate : public Exception{
    public:
        InvalidDate() = default;
        const char* what() const noexcept;
    };

    class NegativeDays : public Exception{
    public:
        NegativeDays() = default;
        const char* what() const noexcept;
    };

    class NotRegistered : public Exception{
    public:
        NotRegistered() = default;
        const char* what() const noexcept;
    };
    
    class InvalidMember : public Exception{
    public:
        InvalidMember() = default;
        const char* what() const noexcept;
    };
    
    class FullList : public Exception{
    public:
        FullList() = default;
        const char* what() const noexcept;
    };
    
    class AlreadyRegistered : public Exception{
    public:
        AlreadyRegistered() = default;
        const char* what() const noexcept;
    };
    
    class AlreadyInvited : public Exception{
    public:
        AlreadyInvited() = default;
        const char* what() const noexcept;
    };

    class RegistrationBlocked : public Exception{
    public:
        RegistrationBlocked() = default;
        const char* what() const noexcept;
    };

    class NotSupported : public Exception{
    public:
        NotSupported() = default;
        const char* what() const noexcept;
    };
        
    class DateMismatch : public Exception{
    public:
        DateMismatch() = default;
        const char* what() const noexcept;
    };

    class InvalidNumber : public Exception{
    public:
        InvalidNumber() = default;
        const char* what() const noexcept;
    };

    class EventAlreadyExists : public Exception{
    public:
        EventAlreadyExists() = default;
        const char* what() const noexcept;
    };

    class EventDoesNotExist : public Exception{
    public:
        EventDoesNotExist() = default;
        const char* what() const noexcept;
    };


} //* End of mtm namespace */

#endif //EXCEPTIONS_H_