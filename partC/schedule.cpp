#include "schedule.h"
#include "../partA/exceptions.h"
#include <iostream>
#include <string>

using std::find;

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using mtm::DateWrap;
using mtm::LinkedList;
using mtm::BaseEvent;
using mtm::EventContainer;

Schedule::Schedule(): event_manager = EventContainer(){
    }

~Schedule(){
}

void addEvents(const EventContainer& event_container)
{
    EventIterator *event_exist = event_container.it;
    EventIterator *it = event_container.it;
    while(event_exist)
    {
        if(event_manager.contains(*event_exist))
        {
            throw mtm::EventAlreadyExists();
        }
    }
    while(it)
    {
        event_manager.insert(*it);
    }
}

void registerToEvent(Date event_date, string event_name, int student)
{
    BaseEvent event(event_date, event_name);
    BaseEvent is_event_exist = find(event_manager.it, 0 , event);
    if(!is_event_exist)
    {
        throw mtm::EventDoesNotExist();
    }
    if() ///need to check if the event is closed / open / have a custom registraions condition
    is_event_exist.registerParticipant(student);
}

void unregisterFromEvent(Date event_date, string event_name, int student)
{
    BaseEvent event(event_date, event_name);
    BaseEvent is_event_exist = find(event_manager.it, 0 , event);
    if(!is_event_exist)
    {
        throw mtm::EventDoesNotExist();
    }
    is_event_exist.unregisterParticipant(student);
}

void printAllEvents();

void printMonthEvents(int month, int year);

void printSomeEvents(class predicate, bool verbose);

void printEventDetails(string event_name, Date event_date);