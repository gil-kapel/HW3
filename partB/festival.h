#ifndef FESTIVAL_H_
#define FESTIVAL_H_
#include "event_container.h"

namespace mtm{
    class Festival: public EventContainer{
        DateWrap date;
    public:
    Festival(DateWrap new_date);//<>
    Festival(const Festival& festival);
    ~Festival(){}
    Festival& operator=(const Festival& festival);
    void add(const BaseEvent& event);// add new event if not similar
    // void begin();
    // void end();
    };
}

// // mtm:festival festival(mtm::datewrap)


#endif //FESTIVAL_H_
