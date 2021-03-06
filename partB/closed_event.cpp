#include "closed_event.h"

using std::string;
using mtm::DateWrap;
using mtm::LinkedList;
using mtm::BaseEvent;
using mtm::ClosedEvent;

ClosedEvent::ClosedEvent(DateWrap new_date, string new_name):
    BaseEvent(new_date,new_name){
    invetee_list = LinkedList<int*>();

}

ClosedEvent::ClosedEvent(const ClosedEvent& closed_event):
    BaseEvent(closed_event){
        Node<int*>* iterator = closed_event.invetee_list.getFirst();
        for (; iterator ; iterator = iterator->getNext())
        {
            int* student_ptr = new int(*iterator->getData());
            invetee_list.insert(student_ptr);
        }
    }

void ClosedEvent::addInvitee(int student)
{
    if(student < min_student_number || student > max_student_number)
    {
        throw mtm::InvalidStudent();
    }
    int* student_ptr = new int(student);
    if(invetee_list.contains(student_ptr))
    {
        delete student_ptr;
        throw mtm::AlreadyInvited();
    }
    invetee_list.insert(student_ptr);
}

void ClosedEvent::registerParticipant(int student)
{
    if(student < min_student_number || student > max_student_number)
    {
        throw mtm::InvalidStudent();
    }
    int* student_ptr = new int(student);
    if(invetee_list.contains(student_ptr))
    {
        if(members_list.contains(student_ptr))
        {
            delete student_ptr;
            throw mtm::AlreadyRegistered();
        }
        members_list.insert(student_ptr);
    }
    else
    {
        delete student_ptr;
        throw mtm::RegistrationBlocked();
    } 
}

BaseEvent* ClosedEvent::clone() const{
    return new ClosedEvent(*this);
}