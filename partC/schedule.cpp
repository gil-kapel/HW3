#include "schedule.h"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using mtm::DateWrap;
using mtm::BaseEvent;
using mtm::EventContainer;
using mtm::Schedule;
using std::list;

//* compare events for sorting them in the event manager 
//  use the opertor< from BaseEvent class to determine if event1 is earlier then event2
// if both off the events are in the same date, the comparation will be lixographic 
static bool compare_events(BaseEvent* event1, BaseEvent* event2)
{
    return *event1 < *event2;
}

Schedule::Schedule(): event_manager(){
}

Schedule::~Schedule()
{
    for(BaseEvent* event : event_manager)
    {
        delete event; //need to delete the clone events
    }
}

void Schedule::addEvents(const EventContainer& event_container)
{
    EventContainer::EventIterator iter(event_container.events_list.getFirst());
    while(iter.iterator) // first loop to check if there are events that already exist in our event manager
    {
        BaseEvent& current_event = *iter;
        for(BaseEvent* event :event_manager)
        {
            if((event->getEventDate() == current_event.getEventDate()) &&
               (event->getEventName() == current_event.getEventName()))
            {
                throw mtm::EventAlreadyExists();
                return; // even if one event from the event container exist in our manager, non will be copied
            }
        }
        ++iter;
    }
    EventContainer::EventIterator iter2(event_container.events_list.getFirst());
    while(iter2.iterator) // second loop will copy the events to the event manager if they're not in it
    {
        BaseEvent* cloned_event = (*iter2).clone();
        event_manager.push_back(cloned_event);
        ++iter2;
    }
    event_manager.sort(compare_events);   
}

void Schedule::registerToEvent(DateWrap event_date, string event_name, int student)
{
    for(BaseEvent* event : event_manager)
    {
        if(event->getEventDate() == event_date && event->getEventName() == event_name)
        {
            event->registerParticipant(student);
            return;
        }
    }
    throw mtm::EventDoesNotExist();
}

void Schedule::unregisterFromEvent(DateWrap event_date, string event_name, int student)
{
    for(BaseEvent* event : event_manager)
    {
        if(event->getEventDate() == event_date && event->getEventName() == event_name)
        {
            event->unregisterParticipant(student);
            return;
        }
    }
    throw mtm::EventDoesNotExist();
}

void Schedule::printAllEvents()const
{
    for(BaseEvent* event : event_manager)
    {
        (*event).printShort(cout);
        cout << endl;
    }
}

void Schedule::printMonthEvents(int month, int year)const
{
    DateWrap first_day(1,month,year);
    DateWrap last_day(30,month,year);
    for(BaseEvent* event : event_manager)
    {
        if((event->getEventDate() >= first_day) && (event->getEventDate() <= last_day))
        {
            (*event).printShort(cout);
            cout << endl;
        }
    }
} 

void Schedule::printEventDetails(DateWrap event_date, string event_name)const
{
    for(BaseEvent* event : event_manager)
    {
        if(event->getEventDate() == event_date && event->getEventName() == event_name)
        {
            (*event).printLong(cout);
            cout << endl;
            return;
        }
    }
    throw mtm::EventDoesNotExist();
}
