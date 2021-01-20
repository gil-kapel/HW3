#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_
#include "base_event.h"

namespace mtm{
    class EventContainer{
    protected:
        LinkedList<BaseEvent*> events_list; 
    public:
        class EventIterator{
        protected:
            Node<BaseEvent*>* iterator;
        public:
            explicit EventIterator(Node<BaseEvent*>* event);
            EventIterator(const EventIterator& it);
            EventIterator& operator=(const EventIterator& it);
            ~EventIterator() = default;
            EventIterator operator++();
            BaseEvent* operator*();
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
