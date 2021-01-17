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
        EventContainer(PriorityQueue <int> membersList): () {};//members_list = LinkedList<int>(); // we want empty queue so there is nothing inside 
        EventContainer(const EventContainer& ec) {} // copy constructor
        virtual ~EventContainer() {} //virtual d'tor for abstract parent function 
        virtual void add(BaseEvent&) {
           // mtm::PriorityQueue<int>::add(BaseEvent);//??
            if(){ // choose condition for exception
            throw NotSupported;// write exception
        }
        PriorityQueue::insert(ec);
        }
        virtual void begin() = 0 { // pure virtual function
            return EventContainer::EventIterator() 
        }
        virtual void end() = 0 {  // pure virtual function
           return EventContainer::EventIterator()
        }
        class EventIterator{
            public:
            EventIterator() {}
            EventIterator(const EventIterator& it) {} //copy 
            ~EventIterator() {}
            EventIterator& operator=(const EventIterator& it){ // assignment operator
                if(this == &ec){
                    return *this;            
                }
                EventIterator& operator++(const EventIterator& iter){// ++ operator
                ++iter; // is it right?
                return *this;
                }
                BaseEvent* EventIterator::operator->()//(const EventContainer& ec)
                {
                    return iter; // reference to BaseEvent
                } 
            };
            bool EventContainer::EventIterator operator==(const EventIterator& it, const EventIterator& iter){
                return it == iter; //
            }
            bool EventContainer::EventIterator operator !=(const EventIterator& iter1, const EventIterator& iter2)
            {
                return !(iter1 == iter2);
            }
            

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