#include "festival.h"

using std::ostream;
using std::string;
using mtm::DateWrap;
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
    for (Node<BaseEvent*>* iterator = festival.events_list.getFirst(); iterator == 0 ; iterator = iterator->getNext())
    {
        BaseEvent* event = iterator->getData()->clone();
        events_list.insert(event);
    }
    date = festival.date;
    return *this;
}

void Festival::add(const BaseEvent& event)
{
    BaseEvent* new_event = event.clone();
    if(events_list.contains(new_event))
    {
        delete new_event;
        throw mtm::NotSupported();
    }
    if(date != new_event->getEventDate())
    {
        delete new_event;
        throw mtm::DateMismatch();
    }
    events_list.insert(new_event);

}