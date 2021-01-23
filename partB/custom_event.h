#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_

#include "base_event.h"

namespace mtm{
    template<class CanRegister>
    class CustomEvent : public mtm::BaseEvent{
        CanRegister condition;
    public:
        CustomEvent(mtm::DateWrap new_date, std::string new_name, CanRegister cond);
        CustomEvent(const CustomEvent& custom_event);
        ~CustomEvent() = default;
        void registerParticipant(int student)override;
        mtm::BaseEvent* clone() const;
    };
    template<class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(mtm::DateWrap new_date, std::string new_name, CanRegister cond):
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
            members_list.insert(student_ptr);
        }
        else
        {
            delete student_ptr;
            throw mtm::RegistrationBlocked();
        }
    }
    template<class CanRegister>
    mtm::BaseEvent* CustomEvent<CanRegister>::clone() const
    {
        return new CustomEvent(*this);
    }

} //* End of mtm namespace*/

#endif //CUSTOM_EVENT_H_