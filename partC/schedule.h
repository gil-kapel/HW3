#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "../partB/custom_event.h"
#include "../partB/open_event.h"
#include "../partB/closed_event.h"
#include "../partB/base_event.h"
#include "../partB/linked_list.h"
#include "../partB/event_container.h"
#include <string>
#include <iostream>
#include <list> 


namespace mtm{
    class Schedule{
        std::list<BaseEvent*> event_manager;
    public:
        Schedule();
        ~Schedule();
        void addEvents(const mtm::EventContainer& event_container);
        void registerToEvent(mtm::DateWrap event_date, std::string event_name, int student);
        void unregisterFromEvent(mtm::DateWrap event_date, std::string event_name, int student);
        void printAllEvents()const;
        void printMonthEvents(int month = 1, int year = 2020)const;
        template <class predicate>
        void printSomeEvents(predicate predicate_function, bool verbose = false)const;
        void printEventDetails(mtm::DateWrap event_date, std::string event_name)const;
    };

    template <class predicate>
    void Schedule::printSomeEvents(predicate predicate_function, bool verbose)const
    {
        for(BaseEvent* event : event_manager)
        {
            if(predicate_function(*event))
            {
                if(verbose)
                {
                    (*event).printLong(std::cout);
                    std::cout << std::endl;
                }
                else
                {
                    (*event).printShort(std::cout);
                    std::cout << std::endl;
                }
            }
        }
    }


} //* End of namespace mtm */
#endif // SCHEDULE_H_