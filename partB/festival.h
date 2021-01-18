#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "date_wrap.h"
#include "event_container.h"
#include "event_base.h"

#include <stdlib.h>
#include <string.h>
#include <iostream>


namespace mtm{
    class Festival: public EventContainer{
    public:
    Festival(DateWrap <int>date) :
        Festival::festival(DateWrap <int>date)  {} // we want empty queue so there is nothing inside 
    void Festival::add(const BaseEvent& added_event) override{ // add new event if not similar
        if(added_event.date != Festival.date){ // choose condition for exception
            throw DataMismatch;// write exception
        }
        LinkedList::insert(added_event);
    }
    void Festival::begin(const BaseEvent& first_event){
        return LinkedList::getFirst();
    }
    void Festival::end(const BaseEvent& last_event){
       return LinkedList::getNext(); // is it the one *after* the last event??
    }
// mtm:festival festival(mtm::datewrap)


#endif //FESTIVAL_H_
