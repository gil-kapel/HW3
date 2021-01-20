
#include "../partA/date_wrap.h"
#include "base_event.h"
#include "event_container.h"
#include "../partA/exceptions.h"
#include <string>
#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using mtm::Node;
using mtm::LinkedList;
using mtm::BaseEvent;
using mtm::EventContainer;


EventContainer::EventContainer(const EventContainer& ec)
{
    for (Node<BaseEvent*>* iterator = ec.events_list.getFirst(); iterator == 0 ; iterator = iterator->getNext())
    {
        BaseEvent* event = iterator->getData()->clone();
        events_list.insert(event);
    }
}

EventContainer& EventContainer::operator=(const EventContainer& ec)
{
    if (this == &ec)
    {
        return *this;
    }
    for (Node<BaseEvent*>* iterator = ec.events_list.getFirst(); iterator == 0 ; iterator = iterator->getNext())
    {
        BaseEvent* event = iterator->getData()->clone();
        events_list.insert(event);
    }
    return *this;
}

EventContainer::EventIterator::EventIterator(Node<BaseEvent*>* event):
    iterator(event){
}

EventContainer::EventIterator::EventIterator(const EventIterator& it):
    iterator(it.iterator) {
}

EventContainer::EventIterator& EventContainer::EventIterator::operator=(const EventIterator& it)
{
    if (this == &it)
    {
        return *this;
    }
    iterator = it.iterator;
    return *this;
}

EventContainer::EventIterator EventContainer::EventIterator::operator++(){
    iterator = iterator->getNext();
    return *this;
}

BaseEvent& EventContainer::EventIterator::operator*(){
    BaseEvent* event = iterator->getData();
    return *event;
}

bool EventContainer::EventIterator::operator==(const EventContainer::EventIterator& iter){
    return iterator == iter.iterator;
}

bool EventContainer::EventIterator::operator!=(const EventContainer::EventIterator& iter){
    return(!(iterator == iter.iterator));
}

void EventContainer::add(const BaseEvent& event)
{
    BaseEvent* new_event = event.clone();
    if(events_list.contains(new_event))
    {
        throw mtm::NotSupported();
    }
    events_list.insert(new_event);
}

EventContainer::EventIterator EventContainer::begin()
{
    EventIterator head(events_list.getFirst());
    return head;
}

EventContainer::EventIterator EventContainer::end()
{
    EventIterator tail(0);
    return tail;
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



