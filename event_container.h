#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include "date_wrap.h"
#include "priority_queue.h"
#include "base_event.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::string;
using mtm::PriorityQueue;

namespace mtm{
    class EventContainer{
    // protected:
    //     PriorityQueue<int> membersList(); 
    public:
        EventContainer(){//(DateWrap date, string name){
            // this->date = date;
            // this->name = name;
            // this->membersList = mtm::PriorityQueue<int>::PriorityQueue();
        }
        virtual EventContainer(const EventContainer&) {} // copy constructor
        virtual ~EventContainer() {} // d'tor
        EventContainer& EventContainer::operator= (const EventContainer& ec){ // assignment operator
            if(this != &ec){
                return *this;            
            }
    
        //BaseEvent& operator=(const BaseEvent& event)
        //{
            // if(this == &event)
            // {
            // return *this;
            // // }
            // dateDestroy(date);
            // this->date = event.date;
            // this->name = event.name;
            // this->membersList = event.membersList;
            // return *this;
        //}
        virtual void add(BaseEvent&)
        {
            mtm::PriorityQueue<int>::add(BaseEvent);//??
        }
        virtual void begin()
        {
            //mtm::PriorityQueue<int>::()
        }
        virtual void end()
        {
           return EventContainer::EventIterator()
        }
        // virtual std::ostream& printLong(std::ostream& os)
        // {
        //     return os << printShort() << endl << this->membersList << endl;
        // }
        // virtual BaseEvent* clone() const = 0{
        //     BaseEvent new_event(date, name, membersList);
        //     new_event.membersList = membersList;
        //     return *new_event;
        // }
        // PriorityQueue<int> getMembersList()
        // {
        //     return membersList;
        // }
    };
}
#endif //EVENT_CONTAINER_H_