#ifndef EVENT_CONTAINER_H_
#define VENT_CONTAINER_H_

#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "linked_list.h"
#include "base_event.h"
#include "priority_queue.h"
#include <stdlib.h>
#include <string>
#include <iostream>
using std::string;
using mtm::DateWrap;
using mtm::LinkedList;
using std::endl;

namespace mtm{
    class EventContainer{
    protected:
        LinkedList<int> events_list; 
    public:
        class EventIterator{
        BaseEvent* iter;
        public:
        EventIterator();
        EventIterator(const EventIterator& it);
        EventIterator& operator=(const EventIterator& it);
        ~EventIterator();
        EventIterator& operator++(const EventIterator& iter);
        &BaseEvent EventIterator::operator->();//????
        friend bool operator==(const EventIterator& it, const EventIterator& iter);
        friend bool operator!=(const EventIterator& it, const EventIterator& iter);
        };
        EventContainer();//(PriorityQueue <int> membersList);
        EventContainer(const EventContainer& ec);
        EventContainer& operator=(const EventContainer& ec);
        virtual ~EventContainer();
        virtual void add(BaseEvent&) = 0;
        virtual EventIterator begin();
        virtual EventIterator end();
        //LinkedList<int> getMembersList();
    };
} //* End of mtm namespace*/

#endif //VENT_CONTAINER_H_
