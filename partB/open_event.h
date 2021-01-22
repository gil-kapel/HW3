#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_

#include "base_event.h"

namespace mtm{
    class OpenEvent : public mtm::BaseEvent{
    public:
        OpenEvent(mtm::DateWrap new_date, std::string new_name);
        ~OpenEvent() = default;
        mtm::BaseEvent* clone() const; 
    };
} //* End of mtm namespace*/

#endif //OPEN_EVENT_H
