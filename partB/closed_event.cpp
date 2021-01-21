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

ClosedEvent::~ClosedEvent(){}

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
    BaseEvent* new_event = new ClosedEvent(*this);
    Node<int*>* iterator = this->members_list.getFirst();
    for (; iterator ; iterator = iterator->getNext())
    {
        new_event->insertStudentToList(*iterator->getData());
    }

    return new_event;
}