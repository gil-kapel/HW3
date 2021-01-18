#include "schedule.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using mtm::DateWrap;
using mtm::LinkedList;
using mtm::BaseEvent;
using mtm::EventContainer;
using mtm::Schedule;

Schedule::Schedule(){}

Schedule::~Schedule(){}

void Schedule::addEvents(const EventContainer& event_container)
{
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iter)
    {
        if(event_manager->events_list.contains(*iterator.iter))
        {
            throw mtm::EventAlreadyExists();
        }
         ++iterator.iter;
    }
    iterator = event_manager->begin();
    while(iterator.iter)
    {
        event_manager->add(*iterator.iter);
        ++iterator;
    }
}

void Schedule::registerToEvent(DateWrap event_date, string event_name, int student)
{
    EventContainer::EventIterator iterator = event_manager->begin();
    BaseEvent* event;
    OpenEvent new_event(event_date,event_name);
    event = new_event.clone();
    while(iterator.iter)
    {
        if(iterator.iter == event)
        {
            event->registerParticipant(student);
            delete event;
            return;
        }
        ++iterator;
    }
    delete event;
    throw mtm::EventDoesNotExist();
}

void Schedule::unregisterFromEvent(DateWrap event_date, string event_name, int student)
{
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iter)
    {
        if(iterator.iter->getEventDate() == event_date && iterator.iter->getEventName() == event_name)
        {
            iterator.iter->unregisterParticipant(student);
            return;
        }
        ++iterator;
    }
    throw mtm::EventDoesNotExist();
}

void Schedule::printAllEvents()
{
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iter)
    {
        iterator.iter->printShort(cout);
        ++iterator;
    }
}

void Schedule::printMonthEvents(int month, int year)
{
    DateWrap first_day(1,month,year);
    DateWrap last_day(30,month,year);
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iter->getEventDate() >= first_day && iterator.iter->getEventDate() <= last_day)
    {
        iterator.iter->printShort(cout);
        ++iterator;
    }
}

void Schedule::printSomeEvents(class predicate, bool verbose)
{

}

void Schedule::printEventDetails(string event_name, Date event_date)
{
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iter)
    {
        if(iterator.iter->getEventDate() == event_date && iterator.iter->getEventName() == event_name)
        {
            iterator.iter->printLong(cout);
            return;
        }
        ++iterator;
    }
    throw mtm::EventDoesNotExist();
}