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
using mtm::Node;
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
            Node<BaseEvent*>* iterator;
        public:
            EventIterator(Node<BaseEvent*>* event);
            EventIterator(const EventIterator& it);
            EventIterator& operator=(const EventIterator& it);
            ~EventIterator() = default;
            EventIterator operator++();
            // BaseEvent& EventIterator::operator->();//????
            BaseEvent* EventIterator::operator*();
            friend bool operator==(const EventIterator& it1, const EventIterator& it2);
            friend bool operator!=(const EventIterator& it1, const EventIterator& it2);
            friend class Schedule;
        };
        EventContainer()= default;
        EventContainer(const EventContainer& ec);
        EventContainer& operator=(const EventContainer& ec);
        virtual ~EventContainer() = default;
        virtual void add(BaseEvent* event) = 0;
        EventIterator begin();
        EventIterator end();
        friend class Schedule;
    };
} //* End of mtm namespace*/

#endif //EVENT_CONTAINER_H_
