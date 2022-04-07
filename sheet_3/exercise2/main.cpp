#include "list.h"
#include "node.h"
#include<iostream>
using namespace std;

int main() {
    List list;
    list.append(2);
    list.append(3);
    list.insert(list.first(), 1);
    for (Node* n = list.first(); n != 0; n = list.next(n))
        std::cout << n->value << std::endl;
    List list2 = list;
    for (Node* n = list2.first(); n != 0; n = list2.next(n))
        std::cout << n->value << std::endl;
}

