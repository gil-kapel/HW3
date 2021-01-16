#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_

#include "base_event.h"
using std::string;
using mtm::BaseEvent;
using mtm::LinkedList;

namespace mtm{
    class ClosedEvent : public BaseEvent{
        LinkedList<int> invetee_list;
    public:
        ClosedEvent(DateWrap new_date, string new_name);
        ~ClosedEvent();
        ClosedEvent(const ClosedEvent& closed_event);
        void addInvetee(int student);
        void registerParticipant(int student);
        BaseEvent* clone() const;
    };
} //* End of mtm namespace*/

#endif //CLOSED_EVENT_H_