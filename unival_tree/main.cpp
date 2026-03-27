#include "unival.hpp"




int main(){

    node* root = new node(0);
    root->left= new node(1);
    root->right = new node(1);
    root->right->left = new node(0);
    root->right->right = new node(1);
    root->left->left = new node(1);
    root->left->right = new node(1);
    root->left->left->left = new node(1);
    root->left->left->right= new node(1);
    root->left->right->left = new node(1);
    root->left->right->right = new node(0);


    unival UT;

    std:: cout<< UT.countUnivalSubtrees(root) << std::endl;


    return 0;
}