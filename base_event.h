#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include "date_wrap.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::string;

namespace mtm{
    template<class Data>
    class PriorityQueue{
        typedef struct node
        {
	        Data data;
            struct node* next;
        }Node*;
        Node head;
        Node iterator;
    public:
	    PriorityQueue()
        {
            head = NULL;
            iterator = NULL;
	    }
	    ~PriorityQueue()
        {
            Node position = head;
            while(position)
            {
                Node to_delete = head;
                delete to_delete.data;
                to_delete.next = NULL;
                position = head.next;
                head = position;
                delete to_delete;
            }
        }        
        PriorityQueue& operator=(const PriorityQueue& pq)
        {
            if(this == &pq)
            {
                return *this;
            }
            Node iteartor = head;
            while(iteartor)
            {
                iteartor = head.next;
                delete head;
            }
            iteartor = pq.head;
            while(iteartor)
            {
                insert(iteartor.data);
                iteartor = pq.head.next;
            }
            return *this;
        }
        void insertNodeToHead(Data data)
        {
            Node new_node = new node;
            new_node.data = data;
            if(!head)
            {
                head = new_node;
                head.next = NULL;
            }
            else
            {
                new_node.next = head;
                head = new_node;
            }
        }
        void insertNodeToCurrentPosition(Node position, Data data)
        {
            Node new_node = new node;
            new_node.data = data;
            new_node.next = position.next;
            position.next = new_node;
        }
        void insertNodeToButtom(Node position, Data data)
        {
            Node new_node = new node;
            new_node.data = data;
            position.next = new_node;
            new_node.next = NULL;
        }
        void insert(Data data)
        {
		    if(!head || data > head.data) // The list is empty or the new data is prior
            {
                insertNodeToHead(data);
                return;
            }
            Node position = head;
            while(position.next)
            {
                Node next = position.next;
                if(data > next.data)
                {
                    insertNodeToCurrentPosition(position, data);
                    return;
                }
                position = position.next;
            }
            insertNodeToButtom(position, data);
		}
        void remove(Data data)
        {
            Node position = head;
            if(head.data == data)
            {
                Node to_delete = head;
                delete to_delete.data;
                to_delete.next = NULL;
                head = head.next;
                delete to_delete;
            }
            while(position.next)
            {
                if(position.data == data)
                {
                    Node to_delete = position.next;
                    delete to_delete.data;
                    position.next = to_delete.next;
                    delete to_delete;
                }
                position = position.next;
            }
        }
        Data getFirst()
        {
            if(head == NULL)
            {
                iterator = NULL;
                return NULL;
            }
            iterator = head;
            return head.data;
        }
        Data getNext()
        {
            if(queue->iterator->next == NULL)
            {
                return NULL;
            }
            iterator = iterator.next;
            return iterator.data;
        }
        friend ostream& operator<<(ostream& os, const PriorityQueue& pq);
    };
    template<class Data>
    virtual ostream& operator<<(ostream& os, const PriorityQueue& pq)
    {
        for (Data iterator = mtm::PriorityQueue::getFirst() ; iterator ; iterator = PriorityQueue::getNext())
        {
            os << iterator << endl;
        }
        return os;

    }

    class BaseEvent{
    protected:
        DateWrap date;
        string name;
        PriorityQueue<int> membersList(); 
    public:
        BaseEvent(DateWrap date, string name){
            this->date = mtm::DateWrap::operator=(date);
            this->name = name;
            this->membersList = mtm::PriorityQueue<int>::PriorityQueue();
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
            mtm::PriorityQueue<int>::insert(student);
        }
        virtual void unregisterParticipant(int student)
        {
            mtm::PriorityQueue<int>::remove(student);
        }
        virtual std::ostream& printShort(std::ostream& os)
        {
            return os << this->name << " " << date << endl;
        }
        virtual std::ostream& printLong(std::ostream& os)
        {
            return os << printShort() << endl << this->membersList << endl;
        }
        virtual BaseEvent* clone() const = 0{
            BaseEvent new_event(date, name, membersList);
            new_event.membersList = membersList;
            return *new_event;
        }
        PriorityQueue<int> getMembersList()
        {
            return membersList;
        }
    };

} //* End of mtm namespace*/

#endif //BASE_EVENT_H_