#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include "date_wrap.h"
#include "base_event.h"
#include "event_container.h"
#include "../partA/exceptions.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>


using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using mtm::LinkedList;
using mtm::BaseEvent;
using mtm::EventContainer;


EventContainer::EventContainer{}
//     BaseEvent (new_event){
//     events_list = LinkedList<int>();
// }

EventContainer::EventIterator{}
//     BaseEvent& (new_event) {
//     iter = 0();
// }

EventContainer::EventContainer(const EventContainer& ec): 
BaseEvent (new_event), EventContainer(ec) {
    events_list = LinkedList<int>(new_event.events_list);
}

EventContainer& EventContainer::operator=(const EventContainer& ec): 
{
    if (this == &ec)
    {
        return this*;
    }
    events_list = ec.events_list;
    return this*;
}

EventContainer::~EventContainer() {
	delete events_list;
}

EventContainer::EventIterator();

EventContainer::EventIterator(const EventIterator& it){
    //
}

EventContainer::EventIterator& operator=(const EventIterator& it){
    if (this == &it)
    {
        return this*;
    }
    events_list = ec.events_list;
    //delete
    return this*;
}

EventContainer::EventIterator& operator++(){
    return  Node<Data>::getNext() const
}

BaseEvent& EventIterator::operator->(){

}

EventContainer::~EventIterator()
{
    delete events_list;
}

bool EventContainer::EventIterator::operator==(const EventIterator& it, const EventIterator& iter){
    return(it1 == it2)
}


bool EventContainer::EventIterator:: operator!=(const EventIterator& it, const EventIterator& iter){
    return(!(it1 == it2))
}

void EventContainer::add(BaseEvent&)
{
    if(event_list.contains(event))
    {
        throw mtm::Notsupported();
    }
    events_list.insert(event);
} 

EventContainer::EventIterator begin()
{
    return LinkedList<Data>::getFirst() const;
}


EventContainer::EventIterator end()
{
    //

}









// namespace mtm{
//     class EventContainer{
//     protected:
//         PriorityQueue <int> membersList; 
//     public:
//         EventContainer::EventContainer(PriorityQueue <int> membersList): () {};//members_list = LinkedList<int>(); // we want empty queue so there is nothing inside 
//         EventContainer::EventContainer(const EventContainer& ec) {} // copy constructor
//         EventContainer& EventContainer::operator=(const EventContainer& ec){ //assignment operator
//             if (this == &ec){
// 		        return *this;
//             }
// 	    }
//         virtual ~EventContainer() {} //virtual d'tor for abstract parent function 
//         virtual void add(BaseEvent&) {
//            // mtm::PriorityQueue<int>::add(BaseEvent);//??
//             if(){ // choose condition for exception
//                 throw NotSupported;// write exception
//             }
//             PriorityQueue::insert(ec);
//         }
//         virtual EventContainer::EventIterator begin() = 0 { // pure virtual function 
//         }
//         virtual EventContainer::EventIterator end() = 0 {  // pure virtual function , void or iter?
//            //return 
//         }
//         class EventIterator{
//             public:
//             EventIterator() {}
//             EventIterator(const EventIterator& it) {} //copy 
//             ~EventIterator() {}
//             EventIterator& operator=(const EventIterator& it){ // assignment operator
//                 if(this == &ec){
//                     return *this;            
//                 }
//             }
//             EventIterator& operator++(const EventIterator& iter){// ++ operator
//                 ++iter; // is it right?
//                 return *this;
//             }
//             BaseEvent* EventIterator::operator->(){//(const EventContainer& ec){
//                     return iter; // reference to BaseEvent
//             } 
//         };
//             bool EventContainer::EventIterator operator==(const EventIterator& it, const EventIterator& iter){
//                 return it == iter; //
//             }
//             bool EventContainer::EventIterator operator !=(const EventIterator& iter1, const EventIterator& iter2)
//             {
//                 return !(iter1 == iter2);
//             }
            
//     }
 

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







// namespace mtm{
//     class EventContainer{
//     protected:
//         PriorityQueue <int> membersList; 
//     public:
//         EventContainer::EventContainer(PriorityQueue <int> membersList): () {};//members_list = LinkedList<int>(); // we want empty queue so there is nothing inside 
//         EventContainer::EventContainer(const EventContainer& ec) {} // copy constructor
//         EventContainer& EventContainer::operator=(const EventContainer& ec){ //assignment operator
//             if (this == &ec){
// 		        return *this;
//             }
// 	    }
//         virtual ~EventContainer() {} //virtual d'tor for abstract parent function 
//         virtual void add(BaseEvent&) {
//            // mtm::PriorityQueue<int>::add(BaseEvent);//??
//             if(){ // choose condition for exception
//                 throw NotSupported;// write exception
//             }
//             PriorityQueue::insert(ec);
//         }
//         virtual EventContainer::EventIterator begin() = 0 { // pure virtual function 
//         }
//         virtual EventContainer::EventIterator end() = 0 {  // pure virtual function , void or iter?
//            //return 
//         }
//         class EventIterator{
//             public:
//             EventIterator() {}
//             EventIterator(const EventIterator& it) {} //copy 
//             ~EventIterator() {}
//             EventIterator& operator=(const EventIterator& it){ // assignment operator
//                 if(this == &ec){
//                     return *this;            
//                 }
//             }
//             EventIterator& operator++(const EventIterator& iter){// ++ operator
//                 ++iter; // is it right?
//                 return *this;
//             }
//             BaseEvent* EventIterator::operator->(){//(const EventContainer& ec){
//                     return iter; // reference to BaseEvent
//             } 
//         };
//             bool EventContainer::EventIterator operator==(const EventIterator& it, const EventIterator& iter){
//                 return it == iter; //
//             }
//             bool EventContainer::EventIterator operator !=(const EventIterator& iter1, const EventIterator& iter2)
//             {
//                 return !(iter1 == iter2);
//             }
            
//     }
 

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














































































































































































// #ifndef EVENT_CONTAINER_H_
// #define EVENT_CONTAINER_H_

// #include "date_wrap.h"
// #include "base_event.h"

// #include <stdlib.h>
// #include <string.h>
// #include <iostream>
// using std::string;
// using mtm::LinkedList;
// using mtm::BaseEvent;
// using mtm::EventContainer;


// EventContainer::EventContainer(): 
//     BaseEvent& (new_event){
//     events_list = LinkedList<int>();
// }

// EventContainer::EventIterator(): {
//    iter = 0();
// }

// EventContainer::EventContainer(const EventContainer& ec): 
// BaseEvent& (new_event) {
//     events_list = LinkedList<int>(new_event.events_list);
// }



// // namespace mtm{
// //     class EventContainer{
// //     protected:
// //         PriorityQueue <int> membersList; 
// //     public:
// //         EventContainer::EventContainer(PriorityQueue <int> membersList): () {};//members_list = LinkedList<int>(); // we want empty queue so there is nothing inside 
// //         EventContainer::EventContainer(const EventContainer& ec) {} // copy constructor
// //         EventContainer& EventContainer::operator=(const EventContainer& ec){ //assignment operator
// //             if (this == &ec){
// // 		        return *this;
// //             }
// // 	    }
// //         virtual ~EventContainer() {} //virtual d'tor for abstract parent function 
// //         virtual void add(BaseEvent&) {
// //            // mtm::PriorityQueue<int>::add(BaseEvent);//??
// //             if(){ // choose condition for exception
// //                 throw NotSupported;// write exception
// //             }
// //             PriorityQueue::insert(ec);
// //         }
// //         virtual EventContainer::EventIterator begin() = 0 { // pure virtual function 
// //         }
// //         virtual EventContainer::EventIterator end() = 0 {  // pure virtual function , void or iter?
// //            //return 
// //         }
// //         class EventIterator{
// //             public:
// //             EventIterator() {}
// //             EventIterator(const EventIterator& it) {} //copy 
// //             ~EventIterator() {}
// //             EventIterator& operator=(const EventIterator& it){ // assignment operator
// //                 if(this == &ec){
// //                     return *this;            
// //                 }
// //             }
// //             EventIterator& operator++(const EventIterator& iter){// ++ operator
// //                 ++iter; // is it right?
// //                 return *this;
// //             }
// //             BaseEvent* EventIterator::operator->(){//(const EventContainer& ec){
// //                     return iter; // reference to BaseEvent
// //             } 
// //         };
// //             bool EventContainer::EventIterator operator==(const EventIterator& it, const EventIterator& iter){
// //                 return it == iter; //
// //             }
// //             bool EventContainer::EventIterator operator !=(const EventIterator& iter1, const EventIterator& iter2)
// //             {
// //                 return !(iter1 == iter2);
// //             }
            
// //     }
 

// //     class Example {
// //     protected:
// //         int* array;
// //         int size;
// //     public:
// //         Example(int _size, int defaultValue)
// //         : array(initArray(size, defaultValue)), size(_size) 
// //         {}

// //         Example(const Example& other)
// //         : array(other.array), size(other.size)
// //         {}

// //         Example& operator=(const Example& other)
// //         {
// //             this->array = other.array;
// //             this->size = other.size;
// //         }

// //         void f(Example other){
            
// //         }

// //         Example& generate(){
// //             return *this;
// //         }

// //         static int* initArray(int size, int defaultValue){

// //             array = new int[size];
// //             for(int i = 0 ; i < size; i++){
// //                 array[i] = defaultValue;
// //             }
// //             return array;
// //         }

// //     }

// // void g(){
// //     Example a;
// //     Example b(a);
// //     Example c = a;
// //     Example d = a.generate();


// // }
// // class ExtendedExample;

// // class ExtendedExample : public Example {
// //     int field;
// // public:
// //     ExtendedExample(int size)
// //     : array(initArray(size)), size(size), field(0)
// //     {}
    
// //     ExtendedExample(int size)
// //     : Example(size, 5), field(0)
// //     {}

// //     void updateSomething() override {
// //         field++;
// //         Example::updateSomething();
// //     }

// // }


// #endif //EVENT_CONTAINER_H_
