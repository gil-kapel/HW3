#include "linked_list.h"
#include <iostream>
using mtm::LinkedList;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
int main()
{
	LinkedList members_list;
	members_list.insert(-12);
	members_list.insert(1);
	members_list.insert(4);
	members_list.insert(2);
	members_list.insert(12552);
	members_list.insert(2333);
	members_list.removeData(4);
	LinkedList new_list;
	new_list = members_list;
	cout << new_list << endl;
	return 0;
}