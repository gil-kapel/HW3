#include "linked_list.h"
#include <iostream>
#include <stdio.h>
using mtm::LinkedList;
using mtm::Node;
using namespace std;
int main()
{
	LinkedList<int> members_list;
	members_list.insert(-12);
	members_list.insert(1);
	members_list.insert(4);
	members_list.insert(2);
	members_list.insert(12552);
	members_list.insert(2333);
	members_list.removeData(2);
	Node<int> *head = members_list.getFirst();
	Node<int> *next = head->getNext();
	head = next;
	members_list.get(1);
	if(members_list.contains(2))
	{
		printf("failure %d\n",members_list.get(5));
	}
	else printf("success %d\n",members_list.get(5));

	LinkedList<int> new_list;
	new_list = members_list;
	cout << new_list << endl;
	return 0;
}