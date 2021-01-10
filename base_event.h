#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include "date_wrap.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::string;

namespace mtm{
    
    template<class T>
    struct node {
	    T data;
        node<T>* next;
    };
    
    template<class T>
    class LinkedList{
	    node<T>* head;
    public:
	    LinkedList<T>()
        {
            head = NULL;
	    }
	    ~LinkedList()
        {
            node<T>* new_node = head;
            while(new_node)
            {
                new_node = head->next;
                delete[] head;
            }
        }
        LinkedList& operator=(const LinkedList& list)
        {
            if(this == &list)
            {
                return *this;
            }
            node<T>* iteartor = head;
            while(iteartor)
            {
                delete[] head;
                iteartor = iteartor->next;
            }
            iteartor = list.head;
            while(iteartor)
            {
                insert(iteartor->data);
                iteartor = iteartor->next;
            }
            return *this;
        }
        void insertNodeToHead(T data)
        {
            node<T>* new_node = new node<T>;
            new_node->data = data;
            if(!head)
            {
                head = new_node;
                head->next = NULL;
            }
            else
            {
                new_node->next = head;
                head = new_node;
            }
        }
        void insertNodeToCurrentPosition(node<T>* position, T data)
        {
            node<T>* new_node = new node<T>;
            new_node->data = data;
            new_node->next = position->next;
            position->next = new_node;
        }
        void insertNodeToButtom(node<T>* position, T data)
        {
            node<T>* new_node = new node<T>;
            new_node->data = data;
            position->next = new_node;
            new_node->next = NULL;
        }
        void insert(T data)
        {
		    if(!head || data > head->data) // The list is empty
            {
                insertNodeToHead(data);
                return;
            }
            node<T>* position = head;
            while(position->next)
            {
                if(data > position->next->data)
                {
                    insertNodeToCurrentPosition(position, data);
                    return;
                }
                position = position->next;
            }
            insertNodeToButtom(position, data);
		}
        void remove(T data)
        {
            node<T>* position = head;
            if(head->position == data)
            {
                node<T>* to_delete = head;
                head = head->next;
                delete[] to_delete;
            }
            while(position->next)
            {
                if(position->data == data)
                {
                    node<T>* to_delete = position->next;
                    position->next = position->next->next;
                    delete[] to_delete;
                }
                position = position->next;
            }
        }
        T get(int index)
        {
		    if(index == 0) // Get the head element
            {
			    return this->head->data;
		    }
            else // Get the index of the element
            {
			    node<T>* current = this->head;
			    for(int i = 0; i < index; ++i)
                {
			    	current = current->next;
			    }
			    return current->data;
            }
		}
	    T operator[](int index)
        {
		    return get(index);
        }
};
    
    class BaseEvent{
        DateWrap date;
        string name;
        LinkedList<int> membersList(); 
    public:
        BaseEvent(DateWrap date, string name){
            this->date = mtm::DateWrap::operator=(date);
            this->name = name;
            this->membersList = mtm::LinkedList<int>::LinkedList();
        }
        virtual ~BaseEvent() {}
        BaseEvent& operator=(const BaseEvent& event)
        {
            if(this == &event)
            {
            return *this;
            }
            dateDestroy(date);
            this->date = event.date;
            this->name = event.name;
            this->membersList = event.membersList;
            return *this;
        }
        virtual void registerParticipant(int student)
        {
            mtm::LinkedList<int>::insert(student);
        }
        virtual void unregisterParticipant(int student);
        virtual std::ostream printShort(std::ostream);
        virtual std::ostream printLong(std::ostream);
        virtual BaseEvent* clone() const = 0;
    };

} //* End of mtm namespace*/

#endif //BASE_EVENT_H_