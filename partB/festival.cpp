#include "../partA/date_wrap.h"
#include "event_container.h"
#include "base_event.h"
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

Festival::Festival(DateWrap date): date(date){
}

Festival::Festival(const Festival& festival): 
    date(DateWrap(festival.date)) {
}

Festival& Festival::operator=(const Festival& festival)
{
    if (this == &festival)
    {
        return *this;
    }
    events_list = festival.events_list;
    date = festival.date;
    return *this;
}

void Festival::add(BaseEvent* event)
{
    if(events_list.contains(event))
    {
        throw mtm::NotSupported();
    }
    if(date != event->getEventDate())
    {
        throw mtm::DateMismatch();
    }
    events_list.insert(event->clone());
}