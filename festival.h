#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "date_wrap.h"
#include "priority_queue.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::string;
using mtm::PriorityQueue;

namespace mtm{
    class Festival: public EventContainer{
    public:
    Festival(DateWrap <int>date) :
        Festival::festival(DateWrap <int>date)  {} // we want empty queue so there is nothing inside 
    void Festival::add(const BaseEvent& added_event){ // add new event if not similar
        if(added_event.date != Festival.date){ // choose condition for exception
            throw DataMismatch;// write exception
        }
        PriorityQueue::insert(added_event);
    }
    void Festival::begin(const BaseEvent& first_event){
        return PriorityQueue::getFirst();
    }
    void Festival::end(const BaseEvent& added_event){
       return PriorityQueue::getNext(); // is it the one *after* the last event??
    }
// mtm:festival festival(mtm::datewrap)


#endif //FESTIVAL_H_