/*
Program name: LinkListClass.cpp
Programmer: Tyler Davies
Date: 10-21-21
Version: 3.1
Description: This program contains a class called LinkList whichs hold a series of integers. The
             class has member functions for appending and printing nodes. The main program tests
             the member functions and displays the results after calling each member function.
             Version 2.0 adds a member function named reverse that rearranges the nodes in reversed
             order. Version 3.0 adds member functions for inserting and deleting nodes.
*/

#include<iostream>
using namespace std;

/*
This class contains a struct which holds an integer and a pointer to the next struct; each struct will
be a node in the link list. It also has a pointer to point to the first node; and member functions to
append, reverse, insert, delete, and print the nodes. 
*/
class LinkList
{
private:
    struct List
    {
        int number;
        struct List *next;
    };
    List *head;
public:
    LinkList()
        { head = NULL; }
    void appendNode(int);
    void printNodes() const;
    void reverse();
    void insertingNode(int);
    void deletingNode(int);
    ~LinkList();
};

/*
This function initializes two List pointers, then dynamically creates a List in memory assigning
parameter num to number. Since the new node will be placed at the end of the list, the next pointer
points to null. If node list is empty, head pointer is assigned to the new node; otherwise, the end
of the list is found and the new node is placed at the end.
*/
void LinkList::appendNode(int num)
{
    List *newNode, *nodePtr;

    newNode = new List;
    newNode->number = num;
    newNode->next = NULL;

    if (!head)
        head = newNode;
    else
    {
        nodePtr = head;
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
}

//This function initializes a List pointer to iterate through the node list. It then prints all of
//of the nodes in the list. Since it should not edit any members, it has been declared as constant.
void LinkList::printNodes() const
{
    List *nodePtr;

    nodePtr = head;
    while (nodePtr)
    {
        cout << nodePtr->number << endl;
        nodePtr = nodePtr->next;
    }
}

/*
This function reverses the order of the linked list using three pointers; nodePtr is assigned the
first node, and previous is assigned NULL address since the first node's next pointer will now point
to NULL. Traversing the linked list, the function saves the next node, changes the next pointer from
the next node to the previous node, then assigns the previous and nodePtr the next two nodes respectively.
Once the end of the list is reached, head is assigned the last node which now points to the previous node.
*/
void LinkList::reverse()
{
    List *nodePtr, *next, *previous;

    nodePtr = head;
    previous = NULL;

    while (nodePtr != NULL)
    {
        next = nodePtr->next;
        nodePtr->next = previous;
        previous = nodePtr;
        nodePtr = next;
    }

    head = previous;
}

/*
This function inserts a node within an ascending order linked list. It initializes newNode using the
value passed to num. If the linked list is empty, it makes newNode the first node; otherwise, it
traverses the linked list stopping before a node which contains a value greater than num. Finally,
the function then places newNode in its respective position within the ascending linked list.
*/
void LinkList::insertingNode(int num)
{
    List *newNode, *nodePtr, *previous;

    previous = NULL;
    newNode = new List;
    newNode->number = num;

    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        nodePtr = head;

        while (nodePtr != NULL && nodePtr->number < num)
        {
            previous = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previous == NULL)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previous->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

/*
This function finds a node in a linked list, and deletes it. If the linked list is empty, nothing happens.
If the first node's value is equal to num, that node is deleted; otherwise, the function traverses the
linked list to find the appropriate node to delete. If the deleted node was not at the end of the linked
list, the previous node's next pointer is assigned the node after the one deleted. 
*/
void LinkList::deletingNode(int num)
{
    List *nodePtr, *previous;

    previous = NULL;

    if (!head)
        return;
    
    if (head->number == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while (nodePtr != NULL && nodePtr->number != num)
        {
            previous = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr)
        {
            previous->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//The destructor has been overridden to delete all of the nodes that were dynamically created in memory.
LinkList::~LinkList()
{
    List *nodePtr, *nextNode;

    nodePtr = head;
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

//The main function creates a LinkList object, tests the LinkList member functions, and prints the results.
int main()
{
    LinkList integerList;

    integerList.appendNode(4);
    cout << "Appended 4 to the linked list:" << endl;
    integerList.printNodes();
    cout << endl;    //Outputting new-line character to split each list printed.

    integerList.appendNode(2);
    cout << "Appended 2 to the linked list:" << endl;
    integerList.printNodes();
    cout << endl;

    integerList.appendNode(1);
    cout << "Appended 1 to the linked list:" << endl;
    integerList.printNodes();
    cout << endl;

    integerList.reverse();
    cout << "Reversed the linked list:" << endl;
    integerList.printNodes();
    cout << endl;

    integerList.insertingNode(3);
    cout << "Inserting node containing number 3 into the linked list:" << endl;
    integerList.printNodes();
    cout << endl;

    integerList.insertingNode(5);
    cout << "Inserting node containing number 5 into the linked list:" << endl;
    integerList.printNodes();
    cout << endl;

    integerList.deletingNode(4);
    cout << "Deleting node containing number 4 from the linked list:" << endl;
    integerList.printNodes();
    cout << endl;

    integerList.deletingNode(2);
    cout << "Deleting node containing number 2 from the linked list:" << endl;
    integerList.printNodes();
    cout << endl;

    exit(0);
}