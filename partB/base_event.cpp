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
using mtm::LinkedList;
using mtm::BaseEvent;

BaseEvent::BaseEvent(DateWrap new_date, string new_name):
    date(new_date), name(new_name){
    members_list = LinkedList<int>();
}
BaseEvent::BaseEvent(const BaseEvent& base_event):
    date(DateWrap(base_event.date)), name(string(base_event.name)){
    members_list = LinkedList<int>(base_event.members_list);
}
BaseEvent& BaseEvent::operator=(const BaseEvent& event) 
{
    if(this == &event)
    {
        return *this;
    }
    date = event.date;
    name = event.name;
    members_list = event.members_list;
    return *this;
}
void BaseEvent::registerParticipant(int student)
{
    if(members_list.contains(student))
    {
        throw mtm::AlreadyRegistered();
    }
    this->members_list.insert(student);
}
void BaseEvent::unregisterParticipant(int student)
{
    if(!members_list.contains(student))
    {
        throw mtm::NotRegistered();
    }
    this->members_list.remove(student);
}
std::ostream& BaseEvent::printShort(std::ostream& os)
{
    return os << name << " " << date << endl;
}
std::ostream& BaseEvent::printLong(std::ostream& os)
{
    return printShort(os) << endl << members_list << endl;
}
LinkedList<int> BaseEvent::getMembersList()
{
    return members_list;
}