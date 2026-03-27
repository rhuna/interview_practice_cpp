#include "node.hpp"




class unival{
public:

    int countUnivalSubtrees(node* root){
        int count =0;
        isUnival(root, count);
        return count;
    }

private:

    bool isUnival(node* node, int&count){

        if (node == nullptr)
        {
            std::cout << "Root is null!" << std::endl;
        }

        if(node==nullptr){
            return true;
        }

        bool leftIsUnival = isUnival(node->left, count);
        bool rightIsUnival = isUnival(node->right, count);

        if(!leftIsUnival || !rightIsUnival){
            return false;
        }

        if(node->left != nullptr && node->left->val != node->val){
            return false;
        }

        if(node->right != nullptr && node->right->val != node->val){
            return false;
        }


        count++;
        return true;
    };
};