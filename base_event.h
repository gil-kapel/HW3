#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include "date_wrap.h"

class BaseEvent{
    DateWrap date;
    char* name;
    int members_list[20000]; 
public:
    BaseEvent(DateWrap date, char* name);
    ~BaseEvent();
    BaseEvent& operator=(const BaseEvent& date);
    void registerParticipant(int student);
    void unregisterParticipant(int student);
    std::ostream printShort(std::ostream);
    std::ostream printLong(std::ostream);
   //*clone();
};

#endif //BASE_EVENT_H_