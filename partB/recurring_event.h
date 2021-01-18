#ifndef RECURRING_EVENT_H
#define RECURRING_EVENT_H

#include "event_container.h"

using std::string;
using mtm::LinkedList;
using mtm::EventContainer;
using mtm::DateWrap;


namespace mtm{
    template <class EventType>
    class RecuuringEvent : public EventContainer{
        EventType event;
        int num_occurrences;
        int interval_days;
    public:
        RecuuringEvent(Date first_date, string name, int num_occurrences, int interval_days);
        RecuuringEvent(const RecuuringEvent& rec_event);
        void add(const BaseEvent& new_event) override;
    };

#endif //RECURRING_EVENT_H

