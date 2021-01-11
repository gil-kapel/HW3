
#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_

#include "date_wrap.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::string;
using mtm::BaseEvent;
using mtm::PriorityQueue;

namespace mtm{
    class ClosedEvent : public mtm::BaseEvent{
        PriorityQueue<int> inveteeList;
    public:
        ClosedEvent(DateWrap date, string name)
        {
            this->date = date;
            this->name = name;
            this->membersList = mtm::PriorityQueue<int>::PriorityQueue();
            inveteeList();
        }
        ~ClosedEvent() override
        {
            delete date;
            delete membersList;
            delete name;
            delete inveteeList;
        }
        addInvetee(int student)
        {
            PriorityQueue<int>::insert(student);
        }
        ClosedEvent* clone() const override{
            BaseEvent* clone_event = clone();

        }
    };
} //* End of mtm namespace*/

#endif //CLOSED_EVENT_H_