#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include "date_wrap.h"
#include "priority_queue.h"
#include "base_event.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::string;
using mtm::PriorityQueue;

namespace mtm{
    class EventContainer{
    protected:
        PriorityQueue <int> membersList; 
    public:
        EventContainer(PriorityQueue <int> membersList)
        : membersList() // we want empty queue so there is nothing inside 
        {}
        virtual EventContainer(const EventContainer&) {} // copy constructor
        virtual ~EventContainer() {} // d'tor
        virtual void add(BaseEvent&) = 0 {
            mtm::PriorityQueue<int>::add(BaseEvent);//??
        }
        virtual void begin() = 0 {
            return EventContainer::EventIterator()
        }
        virtual void end() = 0 {
           return EventContainer::EventIterator()
        }
        class EventIterator{
            public:
            EventIterator& operator= (const EventIterator& it){ // assignment operator
            if(this == &ec){
                return *this;            
            }
            EventIterator& operator++(){
            }
            Number& Number::operator++ (){ // ++ operator
            ++it; // is it right?
            return *this;
            }
            EventIterator operator*(const EventContainer& ec)
            {
                return BaseEvent&; // reference to BaseEvent
            }
            bool operator==(const EventContainer& ec) const;
            bool operator!=(const EventContainer& ec) const;
            
            
    };

  




//     class Example {
//     protected:
//         int* array;
//         int size;
//     public:
//         Example(int _size, int defaultValue)
//         : array(initArray(size, defaultValue)), size(_size) 
//         {}

//         Example(const Example& other)
//         : array(other.array), size(other.size)
//         {}

//         Example& operator=(const Example& other)
//         {
//             this->array = other.array;
//             this->size = other.size;
//         }

//         void f(Example other){
            
//         }

//         Example& generate(){
//             return *this;
//         }

//         static int* initArray(int size, int defaultValue){

//             array = new int[size];
//             for(int i = 0 ; i < size; i++){
//                 array[i] = defaultValue;
//             }
//             return array;
//         }

//     }

// void g(){
//     Example a;
//     Example b(a);
//     Example c = a;
//     Example d = a.generate();


// }
// class ExtendedExample;

// class ExtendedExample : public Example {
//     int field;
// public:
//     ExtendedExample(int size)
//     : array(initArray(size)), size(size), field(0)
//     {}
    
//     ExtendedExample(int size)
//     : Example(size, 5), field(0)
//     {}

//     void updateSomething() override {
//         field++;
//         Example::updateSomething();
//     }

// }


#endif //EVENT_CONTAINER_H_