#ifndef ONE_TIME_EVENT_
#define ONE_TIME_EVENT_

#include "event_container.h"

namespace mtm{
    template<class EventType>
    class OneTimeEvent : public EventContainer{
        EventType event;
    public:
        OneTimeEvent(Date date, string name);
        OneTimeEvent(const OneTimeEvent& one_time_event);
        void add(const BaseEvent& new_event) override;
    };

#endif //ONE_TIME_EVENT_

