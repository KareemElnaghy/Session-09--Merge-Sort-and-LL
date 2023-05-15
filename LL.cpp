//
//  LL.cpp
//  Session 09
//
//  Created by Kareem Elnaghy on 5/2/23.
//

#include <stdio.h>
#include "LL.hpp"
LinkedList::LinkedList()
{
    head = NULL;
    size=0;
}

node* LinkedList::merge(node *a , node *b) // merges two sorted linked lists
{
if(a == NULL)
     return b;      // checks if the left LL has no nodes, then returns b
    
if(b == NULL)       //checks if the right LL has no nodes, returns a
    return a;
    
    node* c = NULL; //creates a new pointer c sets it to NULL
    
if(a->value < b->value) //compares value of a in the left LL to the value of B in the right LL, if the left is less than right therefore we put the a in the linked list
{
    c = a;      //adds the a node to the linked list c
    c->next = merge(a->next, b);    //shifts a to the right and calls the function again to assign the next node in the c linked list
}

if(b->value < a->value) //same as the one above but in the case that the value in the right LL is greater than the left
{
    c = b;
    c->next = merge(a, b->next);
}

    return c;   //returns the new sorted LL
}
node* LinkedList::midPoint(node *head) // finds the midpoint by the runner technique
{
    node* slow = head;
    node* fast = head->next;
    
    while(fast!= NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
node* LinkedList::mergesort(node *head)
{
   if(head == NULL || head->next == NULL)       //base case if the node is one element or if there is no node at all
   {
       return head;
   }

    node* mid = midPoint(head);                     //gets the mid value using runner technique
    
    node* a = head;     //a pointer points to the first node
    node* b=mid->next;  //b pointer points to the node after mid
    mid->next = NULL;   //breaks pointer pointing to b
    a = mergesort(a);   //recursively sorts left LL
    b = mergesort(b);   //recursively sorts right LL
    
    return merge(a, b); //merges the two LL
    
    
    
}
void LinkedList::sort()
{
    head = mergesort(head);
}
void LinkedList::add(int value)
{
    
    if(head==NULL)
    {
        node* n = new node;
        n->value = value;
        n->next = NULL;
        head = n;
    }
    else{
        node* cursor = head;
        while(cursor->next!=NULL)
        {
            cursor = cursor->next;
        }
        node* n = new node;
        n->value = value;
        n->next = NULL;
        cursor->next = n;
    }
    size++;
}

int LinkedList::Size()
{
    return size;
}
void LinkedList::ShowList()
{
    node* cursor = head;
    while(cursor!=NULL)
    {
        std::cout<<cursor->value<<std::endl;
        cursor = cursor->next;
    }
}
