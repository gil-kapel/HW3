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
        EventType event;
        string name;
        Date date;
    public:
        OneTimeEvent() = default;// we have another C'tor in the class, despite this we need this "default" C'tor 
        OneTimeEvent(EventType event, Date date, string name);
        OneTimeEvent(const OneTimeEvent& one_time_event) = default;
        OneTimeEvent& operator=(const OneTimeEvent&) = default;
        ~OneTimeEvent() = default;
        void add(const BaseEvent* new_event) override;
    };
    template<class EventType>
    OneTimeEvent<EventType>::OneTimeEvent(EventType event, Date date, string name):
        event(event), name(name), date(date){
            event = EventType(event);
    }
    template<class EventType>
    void OneTimeEvent<EventType>::add(const BaseEvent* new_event){
        if(!event_list.getFirst()){
            throw mtm::NotSupported;
        }
        events_list.insert(new_event)
    }
}

#endif //ONE_TIME_EVENT_
