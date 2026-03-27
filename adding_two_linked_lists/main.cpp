#include "node.hpp"





int main(){

    node* root1 = new node(4);
    root1->next = new node(2);
    root1->next->next = new node(2);

    node* root2 = new node(2);
    root2->next = new node(4);
    root2->next->next = new node(6);


    //addTwoNumbers(root1, root2);


    printList(addTwoNumbers(root1,root2));




    return 0;
}