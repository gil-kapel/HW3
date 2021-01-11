#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include "date_wrap.h"
#include "priority_queue.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::string;
using mtm::PriorityQueue;

namespace mtm{
    class BaseEvent{
    protected:
        DateWrap date;
        string name;
        PriorityQueue<int> membersList(); 
    public:
        BaseEvent(DateWrap date, string name){
            this->date = date;
            this->name = name;
            this->membersList = mtm::PriorityQueue<int>::PriorityQueue();
        }
        virtual ~BaseEvent() {}
        BaseEvent& operator=(const BaseEvent& event)
        {
            if(this == &event)
            {
            return *this;
            }
            dateDestroy(date);
            this->date = event.date;
            this->name = event.name;
            this->membersList = event.membersList;
            return *this;
        }
        virtual void registerParticipant(int student)
        {
            mtm::PriorityQueue<int>::insert(student);
        }
        virtual void unregisterParticipant(int student)
        {
            mtm::PriorityQueue<int>::remove(student);
        }
        virtual std::ostream& printShort(std::ostream& os)
        {
            return os << this->name << " " << date << endl;
        }
        virtual std::ostream& printLong(std::ostream& os)
        {
            return os << printShort() << endl << this->membersList << endl;
        }
        virtual BaseEvent* clone() const = 0{
            BaseEvent new_event(date, name, membersList);
            new_event.membersList = membersList;
            return *new_event;
        }
        PriorityQueue<int> getMembersList()
        {
            return membersList;
        }
    };

} //* End of mtm namespace*/

#endif //BASE_EVENT_H_