#include "date_wrap.h"
#include "event_container.h"
#include "event_base.h"
#include "festival.h"
#include "../partA/exceptions.h"

#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using mtm::DateWrap;
using mtm::LinkedList;
using mtm::BaseEvent;
using mtm::Festival;

Festival::Festival(DateWrap date):
festival.date = date{
}

Festival::Festival(const Festival& festival): 
    date(DateWrap(festival.date)) {
}

Festival& Festival::operator=(const Festival& festival)
{
    if (this == &festival)
    {
        return this*;
    }
    events_list = festival.events_list;
    date = festival.date;
    return this*;
}

Festival::~Festival(){}

void Festival::add(const BaseEvent& event)
{
    if(events_list.contains(event))
    {
        throw mtm::Notsupported();
    }
    if(festival.date != event.date)
    {
        throw mtm::DateMismatch();
    }
    events_list.insert(event);
} 

// begin and end



    //     Festival::festival(DateWrap <int>date)  {} // we want empty queue so there is nothing inside 
    // void Festival::add(const BaseEvent& added_event) override{ // add new event if not similar
    //     if(added_event.date != Festival.date){ // choose condition for exception
    //         throw DataMismatch;// write exception
    //     }
    //     LinkedList::insert(added_event);
    // }
    // void Festival::begin(const BaseEvent& first_event){
    //     return LinkedList::getFirst();
    // }
    // void Festival::end(const BaseEvent& last_event){
    //    return LinkedList::getNext(); // is it the one *after* the last event??
    // }




