#ifndef RECURRING_EVENT_H
#define RECURRING_EVENT_H

#include "event_container.h"
#include "base_event.h"

namespace mtm{
    template <class EventType>
    class RecurringEvent : public mtm::EventContainer{
    public:
        RecurringEvent() = default;// we have another C'tor in the class, despite this we need this "default" C'tor 
        RecurringEvent(mtm::DateWrap first_date, std::string name, int num_occurrences, int interval_days);
        RecurringEvent(const RecurringEvent& recurring_event) = default;
        RecurringEvent& operator=(const RecurringEvent&) = default;
        ~RecurringEvent() = default;
        void add(const mtm::BaseEvent& event);
    };

    template<class EventType>
    RecurringEvent<EventType>::RecurringEvent(mtm::DateWrap first_date, std::string name,
                                                   int num_occurrences, int interval_days)
    {
        if (num_occurrences < 1)
        {
            throw mtm::InvalidNumber();
        }
        if (interval_days < 1)
        {
            throw mtm::InvalidInterval();
        }
        for(int counter = 0 ; counter < num_occurrences ; counter++)
        {
            EventType event((first_date + (counter * interval_days)) , name);
            mtm::BaseEvent* new_event = event.clone();
            events_list.insert(new_event);
        }
    }

    template<class EventType>
    void RecurringEvent<EventType>::add(const mtm::BaseEvent& event)
    {
        throw mtm::NotSupported();
    }

}

#endif //RECURRING_EVENT_H

