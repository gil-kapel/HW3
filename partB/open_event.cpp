#include "open_event.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using mtm::Exception;
using mtm::DateWrap;
using mtm::LinkedList;
using mtm::BaseEvent;
using mtm::OpenEvent;

OpenEvent::OpenEvent(DateWrap new_date, string new_name):
    BaseEvent(new_date,new_name){
}

BaseEvent* OpenEvent::clone() const{
    BaseEvent* new_event = new OpenEvent(*this);
    Node<int*>* iterator = this->members_list.getFirst();
    for (iterator; iterator ; iterator = iterator->getNext())
    {
        int* student = new int(*iterator->getData());
        new_event->members_list.insert(student);
    }
    return new_event;
}