#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "linked_list.h"
#include <stdlib.h>
#include <string>
#include <iostream>
using std::string;
using mtm::DateWrap;
using mtm::LinkedList;
using std::endl;

namespace mtm{
    class BaseEvent{
    protected:
        DateWrap date;
        string name;
        LinkedList<int> members_list; 
    public:
        BaseEvent(DateWrap new_date, string new_name);
        BaseEvent(const BaseEvent& base_event);
        virtual ~BaseEvent() {}
        virtual BaseEvent& operator=(const BaseEvent& event);
        virtual void registerParticipant(int student);
        virtual void unregisterParticipant(int student);
        virtual std::ostream& printShort(std::ostream& os);
        virtual std::ostream& printLong(std::ostream& os);
        LinkedList<int> getMembersList();
        virtual BaseEvent* clone() const = 0;
    };
} //* End of mtm namespace*/

#endif //BASE_EVENT_H_