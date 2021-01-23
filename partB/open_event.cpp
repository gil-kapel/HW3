#include "open_event.h"

using std::string;
using mtm::DateWrap;
using mtm::BaseEvent;
using mtm::OpenEvent;

OpenEvent::OpenEvent(DateWrap new_date, string new_name):
    BaseEvent(new_date,new_name){
}

OpenEvent::OpenEvent(const OpenEvent& event):
    BaseEvent(event){
    }

BaseEvent* OpenEvent::clone() const{
    return new OpenEvent(*this);
}