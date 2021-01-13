#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
using std::endl;
using std::ostream;
using std::cout;

typedef int Data;

namespace mtm{
    class Node{
        friend class LinkedList;
        Node *next;
        Data data;
    public:
        Node(): data(0), next(0){}
        Node(Data data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
        Data getData()
        {
	        return data;
        }
        void setData(Data new_data)
        {
            data = new_data;
        }
        Node *getNext()
        {
            return next;
        }
        Node& operator=(const Node& node)
        {
            if(this == &node)
            {
                return *this;
            }
            this->data = node.data;
            this->next = node.next;
            return *this;
        }
        void setNext(Node *new_next)
        {
            if(new_next)
            {
                this->next = new_next;
            }
        }
        friend ostream& operator<<(ostream& os, LinkedList& linked);

    };
    class LinkedList{
        Node *head;
        int size;
    public:
        LinkedList(): head(0), size(0){}
        ~LinkedList()
        {
            while(size)
		    {
                removeHead();
            }
        }
        LinkedList& operator=(const LinkedList& linked)
        {
            if(this == &linked)
            {
                return *this;
            }
            for(int i = 0 ; i < size ; i++)
            {
                removeHead();
            }
            Node *temp = linked.head;
            for(int i = 0 ; i < linked.size ; i++)
            {
                this->insert(temp->data);
                temp = temp->next;
            }
            return *this;
        }
        void insertNodeToHead(Data data)
        {
            Node *new_Node = new Node(data, 0);
            if(!head) //empty Node
            {
                head = new_Node;
            }
            else // add to the top of a full Node
            {
                new_Node->next = head;
                head = new_Node;
            }
        }
        void insertNodeToCurrentPosition(Node* position, Data data)
        {
            Node *new_Node = new Node(data, position->next);
            position->next = new_Node;
        }
        void insertNodeToButtom(Node* position, Data data)
        {
            Node *new_Node = new Node(data, 0);
            position->next = new_Node;
        }
        void insert(Data data)
        {
		    if(!head || data > head->data) // The Node is empty or the new data is prior
            {
                insertNodeToHead(data);
                size++;
                return;
            }
            Node* position = head;
            while(position->next)
            {
                if(data > position->next->data)
                {
                    insertNodeToCurrentPosition(position, data);
                    size++;
                    return;
                }
                position = position->next;
            }
            insertNodeToButtom(position, data);
            size++;
		}
        bool contains(Data data)
        {
            Node *temp = head;
            if(!data)
                return false;
            for( int i = 0; i < size; i++) {
                if(data == (temp->data))
                {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
        Data get(int index)
        {
            Node *temp = head;
            if(index >= size) return 0;
            for(int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp->data;
        }
        Node* getFirst()
        {
           	return head;
        }
        int  getSize()
        {
            return size;
        }
        void removeHead()
        {
            if(!head)
            {
                return;
            }
            Node* to_delete = head;
            head = head->next;
            delete to_delete;
            size--;
        }
        void removeData(Data data)
        {
            if(head->data == data)
            {
                removeHead();
                return;
            }
            Node *temp = head;
            for(int i = 0; i < size ; i++)
            {
                if(temp->next->data == data)
                {
                    Node *to_delete = temp->next;
                    temp->next = temp->next->next;
                    delete to_delete;
                    size--;
                    return;
                }
                temp = temp->next;
            }
        }
        friend ostream& operator<<(ostream& os, LinkedList& linked);
    };
    ostream& operator<<(ostream& os, LinkedList& linked)
    {
	    for(int i = 0; i < linked.size; i++) 
        {
            Node* temp = linked.head; 
            os << temp->getData() << endl;
            temp = temp->getNext();
        }
        return os;
    }
}

#endif //LINKED_LIST_H_
