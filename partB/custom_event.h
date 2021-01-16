#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_

#include "base_event.h"
using std::string;
using mtm::BaseEvent;
using mtm::LinkedList;

namespace mtm{
    template<class CanRegister>
    class CustomEvent : public BaseEvent{
        CanRegister condition;
    public:
        CustomEvent(DateWrap new_date, string new_name, CanRegister cond);
        CustomEvent(const CustomEvent& custom_event);
        ~CustomEvent() {}
        void registerParticipant(int student);
        BaseEvent* clone();
    };
    template<class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(DateWrap new_date, string new_name, CanRegister cond):
        BaseEvent(new_date,new_name), condition(cond) {
    }
    template<class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(const CustomEvent& custom_event):
        date(custom_event.date), name(custom_event.name), members_list(custom_event.members_list),
        condition(custom_event.condition){
    }
    template<class CanRegister>
    void CustomEvent<CanRegister>::registerParticipant(int student)
    {
        if(condition(student))
        {
            if(members_list.contains(student))
            {
                throw mtm::AlreadyRegistered();
            }
            this->members_list.insert(student);
        }
        else throw mtm::RegistrationBlocked();
    }
    template<class CanRegister>
    BaseEvent* CustomEvent<CanRegister>::clone() 
    {
        CustomEvent custom_event(this);
        return *custom_event;
    }

} //* End of mtm namespace*/

#endif //CUSTOM_EVENT_H_