#ifndef EXERC_2_LIST_H
#define EXERC_2_LIST_H

#include "node.h"

class List
{
public:
    List (); // create an empty list
    ~List (); // clean up list and all nodes
    Node* first () const; // return pointer to first entry
    Node* next (const Node* n) const; // return pointer to node after n
    void append (int i); // append a value to the end
    void insert (Node* n, int i); // insert a value before n
    void erase (Node* n); // remove n from the list
    int max() const;
    int getSize();

private:
    mutable int max_list;
    int size;
    Node *head;
    Node *tail;
};

void printList(const List& list);

#endif
