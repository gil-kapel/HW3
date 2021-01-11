#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_

#include "date_wrap.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::string;
using mtm::BaseEvent;

namespace mtm{
    class OpenEvent : public mtm::BaseEvent{
    public:
        OpenEvent(DateWrap date, string name)
        {
            this->date = date;
            this->name = name;
            this->membersList = mtm::PriorityQueue<int>::PriorityQueue();
        }
        ~OpenEvent()
        {
            delete date;
            delete membersList;
            delete name;
        }
    };
} //* End of mtm namespace*/

#endif //OPEN_EVENT_H_