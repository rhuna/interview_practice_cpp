#include <iostream>





class node{

public:
    
    node(int val): val(val), left(nullptr), right(nullptr){};

    node* left;
    node* right;
    int val;



};