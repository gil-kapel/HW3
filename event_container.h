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
            // this->membersList = mtm::PriorityQueue<int>::PriorityQueue();
        }
        virtual EventContainer(const EventContainer&) {} // copy constructor
        virtual ~EventContainer() {} // d'tor
        EventContainer:EventIterator(){
            EventIterator& EventUterator::operator= (const EventIterator& it){ // assignment operator
            if(this == &ec){
                return *this;            
            }
            EventIterator& operator++(){

            }


        }
        virtual void add(BaseEvent&)
        {
            mtm::PriorityQueue<int>::add(BaseEvent);//??
        }
        virtual void begin()
        {
            return EventContainer::EventIterator()
        }
        virtual void end()
        {
           return EventContainer::EventIterator()
        }
        // virtual BaseEvent* clone() const = 0{
        //     BaseEvent new_event(date, name, membersList);
        //     new_event.membersList = membersList;
        //     return *new_event;
        // }
    };
    Number& Number::operator++ (){
        ++iter; // is it right?
        return *this;
    }
#endif //EVENT_CONTAINER_H_