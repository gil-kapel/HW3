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
        template <class predicate>
        void printSomeEvents(predicate predicate_function, bool verbose = false);
        void printEventDetails(string event_name, DateWrap event_date);
    };

    template <class predicate>
    void Schedule::printSomeEvents(predicate predicate_function, bool verbose)
    {
        EventContainer::EventIterator iterator = event_manager->begin();
        while(iterator.iterator)
        {
            if(predicate_function(iterator.iterator->getData()->getEventDate()))
            {
                if(verbose)
                {
                    iterator.iterator->getData()->printLong(cout);
                    return;
                }
                else
                {
                    iterator.iterator->getData()->printShort(cout);
                    return;
                }
            }
            ++iterator;
        }
    }
}
#endif // SCHEDULE_H_