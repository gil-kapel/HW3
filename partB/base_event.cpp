#include "base_event.h"
#include "../partA/exceptions.h"
#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using mtm::DateWrap;
using mtm::Node;
using mtm::LinkedList;
using mtm::BaseEvent;

BaseEvent::BaseEvent(DateWrap new_date, string new_name):
    date(new_date), name(new_name){
    members_list = LinkedList<int*>();
}

BaseEvent::BaseEvent(const BaseEvent& base_event):
    date(DateWrap(base_event.date)), name(string(base_event.name)){
    Node<int*>* iterator = this->members_list.getFirst();
    for (iterator; iterator ; iterator = iterator->getNext())
    {
        int* student = new int(*iterator->getData());
        members_list.insert(student);
    }
}

BaseEvent& BaseEvent::operator=(const BaseEvent& base_event) 
{
    if(this == &base_event)
    {
        return *this;
    }
    date = base_event.date;
    name = base_event.name;
    Node<int*>* iterator = this->members_list.getFirst();
    for (iterator; iterator ; iterator = iterator->getNext())
    {
        int* student = new int(*iterator->getData());
        members_list.insert(student);
    }
    return *this;
}

DateWrap BaseEvent::getEventDate()
{
    return date; ////////////////////////////////////////////////////////////////////brings a copy of the date - not good?
}

string BaseEvent::getEventName()
{
    return name;
}

void BaseEvent::registerParticipant(int student)
{
    if(student < min_student_number || student > max_student_number)
    {
        throw mtm::InvalidStudent();
    }
    int* student_ptr = new int(student);
    if(members_list.contains(student_ptr))
    {
        delete student_ptr;
        throw mtm::AlreadyRegistered();
    }
    members_list.insert(student_ptr);
}

void BaseEvent::unregisterParticipant(int student)
{
    if(student < min_student_number || student > max_student_number)
    {
        throw mtm::InvalidStudent();
    }
    int* student_ptr = new int(student);
    if(!(members_list.contains(student_ptr)))
    {
        delete student_ptr;
        throw mtm::NotRegistered();
    }
    members_list.remove(student_ptr);
}

std::ostream& BaseEvent::printShort(std::ostream& os)
{
    return os << name << " " << date << endl;
}

std::ostream& BaseEvent::printLong(std::ostream& os)
{
    return printShort(os) << endl << members_list << endl;
}

LinkedList<int*> BaseEvent::getMembersList()
{
    return members_list;
}

bool BaseEvent::operator==(const BaseEvent& event) const
{
    return (this->date == event.date) && (this->name == event.name);
}

bool BaseEvent::operator>(const BaseEvent& event) const
{
    if(this->date > event.date)
    {
        return true;
    }
    else if(this->date == event.date)
    {
        return (this->name > event.name);
    }
    return false;    
}

bool BaseEvent::operator<(const BaseEvent& event) const
{
   return event > *this;
}

