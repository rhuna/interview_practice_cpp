#include <iostream>
#include <vector>
#include <sstream>



struct TreeNode {
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(int x) : left(nullptr), right(nullptr) {}
    TreeNode(const std::string& s) : left(nullptr), right(nullptr) {
        sval = s;
    }
    std::string sval = "";
    TreeNode* left;
    TreeNode* right;
};

class Codec {
public:    
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root){
        // Base case: if the node is null, return a marker
        if (!root) return "#"; // Use '#' to represent null nodes
        // Recursive case: serialize the current node and its left and right subtrees
        return root->sval + "," + serialize(root->left) + "," + serialize(root->right);
    };
    


    TreeNode *deserializeHelper(std::istringstream &ss)
    {
        
        //holding current node
        std::string token;
        //getting stream and returning current node
        std::getline(ss, token, ',');
        
        //if current node->val == # then returns nullptr
        if (token == "#")
            return nullptr;

        //creates new node and instantiates node->val to int
        TreeNode *node = new TreeNode(token);
        //looks left gets token from line if token is # then
        //returns it, if token is string then returns it
        node->left = deserializeHelper(ss);
        //looks right gets token from line if token is # then
        //returns it, if token is string then returns it
        node->right = deserializeHelper(ss);


        //returns node that has right and left node children
        return node;
    }

    TreeNode *deserialize(const std::string &data)
    {
        //take in string in stream 
        std::istringstream ss(data);
        //returns current node with right and left children
        return deserializeHelper(ss);
    }
};