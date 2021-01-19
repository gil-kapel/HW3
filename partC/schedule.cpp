#include "schedule.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using mtm::DateWrap;
using mtm::BaseEvent;
using mtm::EventContainer;
using mtm::Schedule;

Schedule::Schedule(){}

Schedule::~Schedule(){}

void Schedule::addEvents(const EventContainer& event_container)
{
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iterator)
    {
        if(event_manager->events_list.contains(iterator.iterator->getData()))
        {
            throw mtm::EventAlreadyExists();
        }
         ++iterator.iterator;
    }
    iterator = event_manager->begin();
    while(iterator.iterator)
    {
        event_manager->add(iterator.iterator->getData());
        ++iterator;
    }
}

void Schedule::registerToEvent(DateWrap event_date, string event_name, int student)
{
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iterator)
    {
        if(iterator.iterator->getData()->getEventDate() == event_date &&
            iterator.iterator->getData()->getEventName() == event_name)
        {
            iterator.iterator->getData()->registerParticipant(student);
            return;
        }
        ++iterator;
    }
    throw mtm::EventDoesNotExist();
}

void Schedule::unregisterFromEvent(DateWrap event_date, string event_name, int student)
{
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iterator)
    {
        if(iterator.iterator->getData()->getEventDate() == event_date &&
           iterator.iterator->getData()->getEventName() == event_name)
        {
            iterator.iterator->getData()->unregisterParticipant(student);
            return;
        }
        ++iterator;
    }
    throw mtm::EventDoesNotExist();
}

void Schedule::printAllEvents()
{
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iterator)
    {
        iterator.iterator->getData()->printShort(cout);
        ++iterator;
    }
}

void Schedule::printMonthEvents(int month, int year)
{
    DateWrap first_day(1,month,year);
    DateWrap last_day(30,month,year);
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iterator->getData()->getEventDate() >= first_day && iterator.iterator->getData()->getEventDate() <= last_day)
    {
        iterator.iterator->getData()->printShort(cout);
        ++iterator;
    }
}

void Schedule::printEventDetails(string event_name, DateWrap event_date)
{
    EventContainer::EventIterator iterator = event_manager->begin();
    while(iterator.iterator)
    {
        if(iterator.iterator->getData()->getEventDate() == event_date &&
           iterator.iterator->getData()->getEventName() == event_name)
        {
            iterator.iterator->getData()->printLong(cout);
            return;
        }
        ++iterator;
    }
    throw mtm::EventDoesNotExist();
}