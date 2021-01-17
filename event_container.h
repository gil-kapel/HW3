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
        LinkedList<int> members_list; //or priority queue
    public:
        EventContainer(PriorityQueue <int> membersList);
        EventContainer(const EventContainer& ec);
        virtual ~EventContainer();
        EventContainer& operator=(const EventContainer& ec);
        virtual void add(BaseEvent&);
        virtual EventContainer::EventIterator begin() = 0;
        virtual EventContainer::EventIterator end() = 0;
        EventContainer::EventIterator(); // what are the arguments?
        EventContainer::EventIterator(const EventIterator& it); // is EC necessary?
        EventContainer::~EventIterator(); //is it virtual too?
        EventContainer::EventIterator& operator=(const EventIterator& it)
        EventContainer::EventIterator& operator++(const EventIterator& iter);
        BaseEvent* EventIterator::operator->();//????
        bool EventContainer::EventIterator operator==(const EventIterator& it, const EventIterator& iter);
        bool EventContainer::EventIterator operator !=(const EventIterator& iter1, const EventIterator& iter2);
        //LinkedList<int> getMembersList();
    };
} //* End of mtm namespace*/

#endif //VENT_CONTAINER_H_