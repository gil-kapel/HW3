#ifndef ONE_TIME_EVENT_
#define ONE_TIME_EVENT_

#include "event_container.h"
#include "base_event.h"

using std::string;
using mtm::LinkedList;
using mtm::EventContainer;
using mtm::BaseEvent;
using mtm::DateWrap;


namespace mtm{
    template<class EventType>
    class OneTimeEvent : public EventContainer{
    public:
        OneTimeEvent(DateWrap date, string name);
        void add(const BaseEvent& event);
    };
    template<class EventType>
    OneTimeEvent<EventType>::OneTimeEvent(DateWrap date, string name)
    {
        EventType event(date, name);
        BaseEvent* new_event = event.clone();
        events_list.insert(new_event);
    }
    template<class EventType>
    void OneTimeEvent<EventType>::add(const BaseEvent& event){
        BaseEvent* new_event = event.clone();
        if(!events_list.getFirst())
        {
            delete new_event;
            throw mtm::NotSupported();
        }
        events_list.insert(new_event);
    }
}

#endif //ONE_TIME_EVENT_
