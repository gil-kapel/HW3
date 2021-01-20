#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_

#include "base_event.h"

namespace mtm{
    template<class CanRegister>
    class CustomEvent : public BaseEvent{
        CanRegister condition;
    public:
        CustomEvent(DateWrap new_date, string new_name, CanRegister cond);
        CustomEvent(const CustomEvent& custom_event);
        ~CustomEvent() {}
        void registerParticipant(int student);
        BaseEvent* clone() const;
    };
    template<class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(DateWrap new_date, string new_name, CanRegister cond):
        BaseEvent(new_date,new_name){
        condition = CanRegister(cond);
    }
    template<class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(const CustomEvent& custom_event):
        BaseEvent(custom_event){
        condition = CanRegister(custom_event.condition);
    }
    template<class CanRegister>
    void CustomEvent<CanRegister>::registerParticipant(int student)
    {
        int max_student_number = 1234567890;
        int min_student_number = 1;
        if(student < min_student_number || student > max_student_number)
        {
            throw mtm::InvalidStudent();
        }
        int* student_ptr = new int(student);
        if(condition(student))
        {
            if(members_list.contains(student_ptr))
            {
                delete student_ptr;
                throw mtm::AlreadyRegistered();
            }
            this->members_list.insert(student_ptr);
        }
        else throw mtm::RegistrationBlocked();
    }
    template<class CanRegister>
    BaseEvent* CustomEvent<CanRegister>::clone() const
    {
        return new CustomEvent(*this);
    }

} //* End of mtm namespace*/

#endif //CUSTOM_EVENT_H_