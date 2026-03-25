#include "XOR_linkedList.hpp"




int main(){

    XORLinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);

    Node *n = list.get(2);

    if (n)
    {
        std::cout << n->val << "\n"; // should print 30
    }

    return 0;
}