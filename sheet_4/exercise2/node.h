#ifndef EXERC_2_NODE_H
#define EXERC_2_NODE_H

class Node {
public:
    Node();
    ~Node();
    friend class List;
    int value;
private:
    Node* next;
};

#endif
