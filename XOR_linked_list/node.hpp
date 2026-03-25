#include <iostream>
#include <vector>




class Node {

public:

    int val;
    uintptr_t both;

    Node(int node): val(node), both(0){};

};


Node* XOR(Node* a, Node* b){
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}