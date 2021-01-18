#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "linked_list.h"
#include "base_event.h"
#include <stdlib.h>
#include <string>
#include <iostream>
using std::string;
using mtm::DateWrap;
using mtm::LinkedList;
using mtm::BaseEvent;
using std::endl;

namespace mtm{
    class EventContainer{
    protected:
        LinkedList<BaseEvent*> events_list; 
    public:
        class EventIterator{
        protected:
            Node* iter;
        public:
            EventIterator() = default;
            EventIterator(const EventIterator& it);
            EventIterator& operator=(const EventIterator& it);
            ~EventIterator(); //should be also virtual???
            EventIterator& operator++();
            // BaseEvent& EventIterator::operator->();//????
            BaseEvent& EventIterator::operator*();
            friend bool operator==(const EventIterator& it, const EventIterator& iter);
            friend bool operator!=(const EventIterator& it, const EventIterator& iter);
            friend class schedule;
        };
        EventContainer()= default;//(BaseEvent& new_event);//(PriorityQueue <int> membersList);
        EventContainer(const EventContainer& ec);
        EventContainer& operator=(const EventContainer& ec);
        virtual ~EventContainer() = default;
        virtual void add(BaseEvent&) = 0;
        virtual EventIterator begin();
        virtual EventIterator end();
        friend class schedule;
        //LinkedList<int> getMembersList();
    };
} //* End of mtm namespace*/

#endif //EVENT_CONTAINER_H_
