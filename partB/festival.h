#ifndef FESTIVAL_H_
#define FESTIVAL_H_
#include "event_container.h"

namespace mtm{
    class Festival: public mtm::EventContainer{
        mtm::DateWrap date;
    public:
    Festival(mtm::DateWrap new_date);
    Festival(const Festival& festival);
    ~Festival(){}
    Festival& operator=(const Festival& festival);
    void add(const mtm::BaseEvent& event);
    };
}

#endif //FESTIVAL_H_
