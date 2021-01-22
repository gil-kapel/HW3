
#include "../partA/date_wrap.h"
#include "base_event.h"
#include "event_container.h"
#include "../partA/exceptions.h"
#include <string>
#include <iostream>

using std::ostream;
using std::string;
using mtm::Node;
using mtm::BaseEvent;
using mtm::EventContainer;

EventContainer::EventContainer(const EventContainer& ec)
{
    for (Node<BaseEvent*>* iterator = ec.events_list.getFirst(); iterator == 0 ; iterator = iterator->getNext())
    {
        BaseEvent* event = iterator->getData()->clone();
        events_list.insert(event);
    }
}

EventContainer& EventContainer::operator=(const EventContainer& ec)
{
    if (this == &ec)
    {
        return *this;
    }
    for (Node<BaseEvent*>* iterator = ec.events_list.getFirst(); iterator == 0 ; iterator = iterator->getNext())
    {
        BaseEvent* event = iterator->getData()->clone();
        events_list.insert(event);
    }
    return *this;
}

EventContainer::EventIterator::EventIterator(Node<BaseEvent*>* event):
    iterator(event){
}

EventContainer::EventIterator::EventIterator(const EventIterator& it):
    iterator(it.iterator) {
}

EventContainer::EventIterator& EventContainer::EventIterator::operator=(const EventIterator& it)
{
    if (this == &it)
    {
        return *this;
    }
    iterator = it.iterator;
    return *this;
}

EventContainer::EventIterator EventContainer::EventIterator::operator++(){
    iterator = iterator->getNext();
    return *this;
}

BaseEvent& EventContainer::EventIterator::operator*(){
    BaseEvent* event = iterator->getData();
    return *event;
}

bool EventContainer::EventIterator::operator==(const EventContainer::EventIterator& iter){
    return iterator == iter.iterator;
}

bool EventContainer::EventIterator::operator!=(const EventContainer::EventIterator& iter){
    return(!(iterator == iter.iterator));
}

void EventContainer::add(const BaseEvent& event)
{
    BaseEvent* new_event = event.clone();
    if(events_list.contains(new_event))
    {
        throw mtm::NotSupported();
    }
    events_list.insert(new_event);
}

EventContainer::EventIterator EventContainer::begin()
{
    EventIterator head(events_list.getFirst());
    return head;
}

EventContainer::EventIterator EventContainer::end()
{
    EventIterator tail(0);
    return tail;
}
