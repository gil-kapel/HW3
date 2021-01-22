#ifndef ONE_TIME_EVENT_
#define ONE_TIME_EVENT_

#include "event_container.h"
#include "base_event.h"

namespace mtm{
    template<class EventType>
    class OneTimeEvent : public mtm::EventContainer{
    public:
        OneTimeEvent(mtm::DateWrap date, std::string name);
        void add(const mtm::BaseEvent& event);
    };

    template<class EventType>
    OneTimeEvent<EventType>::OneTimeEvent(mtm::DateWrap date, std::string name)
    {
        EventType event(date, name);
        mtm::BaseEvent* new_event = event.clone();
        events_list.insert(new_event);
    }
    template<class EventType>
    void OneTimeEvent<EventType>::add(const mtm::BaseEvent& event)
    {
        throw mtm::NotSupported();
    }
}

#endif //ONE_TIME_EVENT_
