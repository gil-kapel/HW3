#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <iostream>

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
}

} //* End of mtm namespace*/

#endif //PRIORITY_QUEUE_H_