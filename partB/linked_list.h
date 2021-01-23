#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>

namespace mtm
{
    template <class Data>
    class LinkedList;
    template <class Data>
    class Node{
        friend class LinkedList<Data>;
        Node *next;
        Data data;
    public:
        Node(): data(0), next(nullptr){}
        Node(Data data = 0, Node* next = nullptr);
        Data getData() const;
        Node* getNext() const;
        Node& operator=(const Node& node);
        void setNext(Node *new_next);
    };
    template<class Data>
    class LinkedList{
        Node<Data> *head;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void insertNodeToHead(Data data);
        void insertNodeToCurrentPosition(Node<Data>* position, Data data);
        void insertNodeToButtom(Node<Data>* position, Data data);
        void insert(Data data);
        bool contains(Data data);
        Node <Data>* getFirst() const;
        int  getSize() const;
        void removeHead();
        void remove(Data data);
    };
    template<class Data>
    Node<Data>::Node(Data data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
    template<class Data>
    Data Node<Data>::getData() const
    {
        return data;
    }
    template<class Data>
    Node<Data>* Node<Data>::getNext() const
    {
        return this->next;
    }
    template<class Data>
    Node<Data>& Node<Data>::operator=(const Node& node)
    {
        if(this == &node)
        {
            return *this;
        }
        this->data = node.data;
        this->next = node.next;
        return *this;
    }
    template<class Data>
    void Node<Data>::setNext(Node *new_next)
    {
        if(new_next)
        {
            this->next = new_next;
        }
    }

    template<class Data>
    LinkedList<Data>::LinkedList(): head(nullptr), size(0){
    }
    template<class Data>
    LinkedList<Data>::~LinkedList()
    {
        while(size)
        {
            removeHead();
        }
    }
    template<class Data>
    void LinkedList<Data>::insertNodeToHead(Data data)
    {
        Node<Data> *new_Node = new Node<Data>(data, nullptr);
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
    template<class Data>
    void LinkedList<Data>::insertNodeToCurrentPosition(Node<Data>* position, Data data)
    {
        Node<Data> *new_Node = new Node<Data>(data, position->next);
        position->next = new_Node;
    }
    template<class Data>
    void LinkedList<Data>::insertNodeToButtom(Node<Data>* position, Data data)
    {
        Node<Data> *new_Node = new Node<Data>(data, nullptr);
        position->next = new_Node;
    }
    template<class Data>
    void LinkedList<Data>::insert(Data data)
    {
        if(!head || *data < *head->data) // The Node is empty or the new data is prior
        {
            insertNodeToHead(data);
            size++;
            return;
        }
        Node<Data>* position = head;
        while(position->next)
        {
            if(*data < *position->next->data)
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
    template<class Data>
    bool LinkedList<Data>::contains(Data data)
    {
        if(head == nullptr)
        {
            return false;
        }
        Node<Data> *temp = head;
        for(int i = 0; i < size; i++) {
            if(*data == *temp->data)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    template<class Data>
    Node<Data>* LinkedList<Data>::getFirst() const
    {
        return this->head;
    }
    template<class Data>
    int LinkedList<Data>::getSize()const
    {
        return size;
    }
    template<class Data>
    void LinkedList<Data>::removeHead()
    {
        if(!head)
        {
            return;
        }
        Node<Data>* to_delete = head;
        head = head->next;
        delete to_delete->data;
        delete to_delete;
        size--;
    }
    template<class Data>
    void LinkedList<Data>::remove(Data data)
    {
        if(*head->data == *data)
        {
            delete data;
            removeHead();
            return;
        }
        Node<Data> *temp = head;
        for(int i = 0; i < size - 1 ; i++)
        {
            if(*temp->next->data == *data)
            {
                Node<Data> *to_delete = temp->next;
                delete to_delete->data;
                temp->next = temp->next->next;
                delete data;
                delete to_delete;
                size--;
                return;
            }
            temp = temp->next;
        }
    }
    template <class Data>
    std::ostream& operator<<(std::ostream& os, const LinkedList<Data>& linked)
    {
        Node<Data>* temp = linked.getFirst(); 
        for(int i = 0; i < linked.getSize(); i++)
        {
            os << *temp->getData() << std::endl;
            temp = temp->getNext();
        }
        return os;
    }
}

#endif //LINKED_LIST_H_