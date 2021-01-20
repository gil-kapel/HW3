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
    return new OpenEvent(*this);
}
//
