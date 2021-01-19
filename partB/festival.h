#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "date_wrap.h"
#include "event_container.h"
#include "event_base.h"

#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::string;
using mtm::DateWrap;
using mtm::LinkedList;
using mtm::BaseEvent;
using mtm::EventContainer;
using std::endl;


namespace mtm{
    class Festival: public EventContainer{
        DateWrap date;
    public:
    Festival(DateWrap new_date);//<>
    Festival(const Festival& festival);
    ~Festival(){}
    Festival& operator=(const Festival& festival);
    void add(const BaseEvent& new_event) override;// add new event if not similar
    void begin();
    void end();
    }
};




// // mtm:festival festival(mtm::datewrap)


#endif //FESTIVAL_H_
