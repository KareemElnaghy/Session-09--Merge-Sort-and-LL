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
     return b;
    
if(b == NULL)
    return a;
    
    node* c = NULL;
    
if(a->value < b->value)
{
    c = a;
    c->next = merge(a->next, b);
}

if(b->value < a->value)
{
    c = b;
    c->next = merge(a, b->next);
}

    return c;
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
   if(head == NULL || head->next == NULL)
   {
       return head;
   }

    node* mid = midPoint(head);
    
    node* a = head;
    node* b=mid->next;
    mid->next = NULL;
    a = mergesort(a);
    b = mergesort(b);
    
    return merge(a, b);
    
    
    
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
