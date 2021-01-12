#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include "date_wrap.h"
#include "priority_queue.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::string;
using mtm::PriorityQueue;

// namespace mtm{
    class EventContainer{
    // protected:
        PriorityQueue<int> membersList(); 
    public:
        EventContainer();// = default
        EventContainer& operator = (const EventContainer&)
        virtual ~EventContainer();
    };

} //* End of mtm namespace*/

#endif //EVENT_CONTAINER_H_