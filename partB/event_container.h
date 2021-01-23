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
            explicit EventIterator(Node<BaseEvent*>* event = nullptr);
            EventIterator(const EventIterator& it);
            EventIterator& operator=(const EventIterator& it);
            ~EventIterator() = default;
            EventIterator operator++();
            BaseEvent& operator*();
            bool operator==(const EventIterator& iter);
            bool operator!=(const EventIterator& iter);
            friend class Schedule;
        };
        EventContainer();
        EventContainer(const EventContainer& ec);
        EventContainer& operator=(const EventContainer& ec);
        virtual ~EventContainer() = default;
        virtual void add(const BaseEvent& event) = 0;
        EventIterator begin();
        EventIterator end();
        friend class Schedule;
    };
} //* End of mtm namespace*/

#endif //EVENT_CONTAINER_H_
