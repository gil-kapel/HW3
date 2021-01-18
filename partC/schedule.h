#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "../partB/custom_event.h"
#include "../partB/open_event.h"
#include "../partB/closed_event.h"
#include "../partB/base_event.h"
#include "../partB/linked_list.h"
#include "../partB/event_container.h"
#include <string>
#include <iostream>
using std::string;
using std::endl;
using mtm::EventContainer;

namespace mtm{
    class Schedule{
        EventContainer *event_manager;
    public:
        Schedule();
        ~Schedule();
        void addEvents(const EventContainer& event_container);
        void registerToEvent(DateWrap event_date, string event_name, int student);
        void unregisterFromEvent(DateWrap event_date, string event_name, int student);
        void printAllEvents();
        void printMonthEvents(int month, int year);
        void printSomeEvents(class predicate, bool verbose);
        void printEventDetails(string event_name, Date event_date);
    };
}
#endif // SCHEDULE_H_