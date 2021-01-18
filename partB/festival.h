#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"

using std::string;
using mtm::LinkedList;
using mtm::EventContainer;
using mtm::DateWrap;


namespace mtm{
    class Festival : public EventContainer{
        Date festival_date;
    public:
        Festival(Date date);
        Festival(const Festival& festival);
        void add(const BaseEvent& new_event) override;
    };

#endif //FESTIVAL_H_
