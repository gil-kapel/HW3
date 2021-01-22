#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "linked_list.h"
#include <string>
#include <iostream>
#include <cstdbool>

namespace mtm{
    class BaseEvent{
    protected:
        mtm::DateWrap date;
        std::string name;
        mtm::LinkedList<int*> members_list; 
    public:
        BaseEvent(mtm::DateWrap new_date, std::string new_name);
        BaseEvent(const BaseEvent& base_event); //copy c'tor, copy the member list
        virtual ~BaseEvent() = default;
        BaseEvent& operator=(const BaseEvent& event);
        mtm::DateWrap getEventDate(); //get the date of a specific event
        std::string getEventName();   //get the name of a specific event
        virtual void registerParticipant(int student);
        void unregisterParticipant(int student);
        std::ostream& printShort(std::ostream& os);
        std::ostream& printLong(std::ostream& os);
        void insertStudentToList(int student); // insert a student into the member list (not to the invette list)
        virtual BaseEvent* clone() const = 0; // to implementation in the abstractic class
	    bool operator==(const BaseEvent& event) const;//compare two events to arrange them in the LinkedList
        bool operator>(const BaseEvent& event) const;
        bool operator<(const BaseEvent& event) const;
        friend class OpenEvent;
        friend class ClosedEvent;

    };

} //* End of mtm namespace*/

const int max_student_number = 1234567890;
const int min_student_number = 1;

#endif //BASE_EVENT_H_

