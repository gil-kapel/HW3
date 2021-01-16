#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_

#include "base_event.h"
using std::string;
using mtm::BaseEvent;
using mtm::LinkedList;

namespace mtm{
    class OpenEvent : public BaseEvent{
    public:
        OpenEvent(DateWrap new_date, string new_name);
        ~OpenEvent(){}
        BaseEvent* clone() const;
    };
} //* End of mtm namespace*/

#endif //OPEN_EVENT_H_