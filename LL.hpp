//
//  LL.hpp
//  LinkedList
//
//  Created by Esraa Hamdi Abbas on 11/1/21.
//

#ifndef LL_hpp
#define LL_hpp

#include <stdio.h>
#include <iostream>
struct node
{
    int value;
    node* next;
};
class LinkedList
{
private:
    node* head;
    int size;
    node *merge (node *a,node* b);
    node* mergesort(node* head);
    node* midPoint(node* head);
public:
    LinkedList();
    void add(int value);
    void sort ();
    int Size();
    void ShowList();
};
#endif /* LL_hpp */
