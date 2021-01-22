#include "open_event.h"

using std::string;
using mtm::DateWrap;
using mtm::BaseEvent;
using mtm::OpenEvent;

OpenEvent::OpenEvent(DateWrap new_date, string new_name):
    BaseEvent(new_date,new_name){
}

BaseEvent* OpenEvent::clone() const{
    BaseEvent* new_event = new OpenEvent(*this);
    Node<int*>* iterator = this->members_list.getFirst();
    for (; iterator ; iterator = iterator->getNext())
    {
        new_event->insertStudentToList(*iterator->getData());
    }
    return new_event;
}