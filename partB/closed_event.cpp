#include "closed_event.h"

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
using mtm::ClosedEvent;

ClosedEvent::ClosedEvent(DateWrap new_date, string new_name):
    BaseEvent(new_date,new_name){
    invetee_list = LinkedList<int>();

}

ClosedEvent::ClosedEvent(const ClosedEvent& closed_event):
    BaseEvent(closed_event){
    invetee_list = LinkedList<int>(closed_event.invetee_list);
}

ClosedEvent::~ClosedEvent(){}

void ClosedEvent::addInvetee(int student)
{
    if(invetee_list.contains(student))
    {
        throw mtm::AlreadyInvited();
    }
    invetee_list.insert(student);
}

void ClosedEvent::registerParticipant(int student)
{
 
    if(invetee_list.contains(student))
    {
        if(members_list.contains(student))
        {
            throw mtm::AlreadyRegistered();
        }
        this->members_list.insert(student);
    }
    else throw mtm::RegistrationBlocked();
}

BaseEvent* ClosedEvent::clone() const{
    return new ClosedEvent(*this);
}