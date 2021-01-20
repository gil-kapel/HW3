#ifndef RECURRING_EVENT_H
#define RECURRING_EVENT_H

#include "event_container.h"

namespace mtm{
    template <class EventType>
    class RecurringEvent : public EventContainer{
        EventType event;
        string name;
        int num_occurrences;
        int interval_days;
        DateWrap first_date;
    public:
        RecurringEvent() = default;// we have another C'tor in the class, despite this we need this "default" C'tor 
        RecurringEvent(EventType event, string name, int num_occurrences, int interval_days, Date first_date);
        RecurringEvent(const RecurringEvent& recurring_event) = default;
        RecurringEvent& operator=(const RecurringEvent&) = default;
        ~RecurringEvent() = default;
        void add(BaseEvent* new_event) override;
    };

    template<class EventType>
    RecurringEvent<EventType>::RecurringEvent(EventType event, string name, int num_occurrences, int interval_days, Date first_date): 
        event(event), name(name), num_occurrences(num_occurrences), interval_days(interval_days), first_date(first_date) {
        if (num_occurrences < 1){
            throw mtm::InvalidNumber();
        }
        if (interval_days < 1){
            throw mtm::InvalidDate();
        }
    }

    template<class EventType>
    void RecurringEvent<EventType>::add(BaseEvent* new_event){
        if(events_list.contains(event))
        {
            throw mtm::NotSupported();
        }
        events_list.insert(new_event->clone());
    }
}

#endif //RECURRING_EVENT_H