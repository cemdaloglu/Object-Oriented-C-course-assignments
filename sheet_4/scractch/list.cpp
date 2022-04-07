#include "list.h"
#include "node.h"
#include <iostream>

using namespace std;

List::List() {
    size = 0;
    head = new Node();
    tail = new Node();
}

List::~List() {
    Node *temp = new Node();
    for (int i = 0; i < getSize(); i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void List::insert(Node* n, int i){
    if (head == n) {
        Node* n = new Node();
        n->value = i;
        n->next = head;
        head = n;
    }

    else {
        Node *p = head;
        for (p; p == n; p = p->next);
        Node* m = new Node();
        m->value = i;

        m->next = p->next;

        p->next = m;
    }
    size++;
}

void List::erase(Node* n)
{
    if(head == n)
    {
        if(head->next == NULL)
        {
            cout << "There is only one node." <<
                 " The list can't be made empty ";
            return;
        }

        head->value = head->next->value;
        n = head->next;
        head->next = head->next->next;
        delete n;
    }
    else {
        Node *prev = head;
        while (prev->next != NULL && prev->next != n)
            prev = prev->next;

        if (prev->next == NULL) {
            cout << "\nGiven node is not present in Linked List";
        }

        prev->next = prev->next->next;

        delete n;
    }
    size--;
}

void List::append(const int i) {
    Node *new_element = new Node();
    new_element->value = i;
    new_element->next = NULL;
    if (size==0)
    {
        head->value = new_element->value;
        head->next = NULL;
        tail->value = new_element->value;
        tail->next = NULL;
    }
    else if (size==1)
    {
        head->next = new_element;
        tail = new_element;
    } else
    {
        tail->next = new_element;
        tail = new_element;
    }
    size++;
}

int List::getSize() {
    return size;
}

Node *List::first() const{
    return head;
}

Node *List::next(const Node *n) const{
    Node *temp1 = new Node();
    temp1 = head;
    bool flag = true;
    while (flag)
    {
        if (temp1 == n) {
            temp1 = temp1->next;
            flag = false;
        }
        else
            temp1 = temp1->next;
    }
    return temp1;
}

int List::max() const {
    if (size==0)
        cout << "\nList is empty";
    else{
        max_list = head->value;
        for (Node* n = next(first()); n != 0; n = next(n)) {
            if (n->value > max_list)
                max_list = n->value;
        }
    }
    return max_list;
}

void printList (const List& list)
{
    for (const Node* n = list.first(); n != 0; n = list.next(n)) {
        std::cout << n->value << std::endl;
    }
    std::cout << "max: " << list.max() << std::endl;
}
