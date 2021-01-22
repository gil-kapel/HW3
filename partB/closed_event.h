#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_

#include "base_event.h"

namespace mtm{
    class ClosedEvent : public mtm::BaseEvent{
        mtm::LinkedList<int*> invetee_list;
    public:
        ClosedEvent(mtm::DateWrap new_date, std::string new_name);
        ~ClosedEvent() = default;
        ClosedEvent(const mtm::ClosedEvent& closed_event);
        void addInvitee(int student);
        void registerParticipant(int student) override;
        mtm::BaseEvent* clone() const;
    };
} //* End of mtm namespace*/

#endif //CLOSED_EVENT_H_