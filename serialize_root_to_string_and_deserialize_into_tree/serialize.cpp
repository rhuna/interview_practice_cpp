#include <iostream>
#include <vector>
#include <sstream>



struct TreeNode {
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(const std::string& s) : val(0), left(nullptr), right(nullptr) {
        // Convert string to integer value
        val = std::stoi(s);
    }
    int val = std::stoi(sval);
    std::string sval = "";
    TreeNode* left;
    TreeNode* right;
};

class Codec {
public:     // Encodes a tree to a single string.
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root){
        // Base case: if the node is null, return a marker
        if (!root) return "#"; // Use '#' to represent null nodes
        // Recursive case: serialize the current node and its left and right subtrees
        return std::to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    };
    int serialize(const std::string& s) {
        // Convert string to integer value
        return std::stoi(s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const std::string& data){
        // Use a stringstream to read the serialized data
        std::istringstream ss(data);
        // Read the next token (value or marker) from the stream
        std::string token;
        // Get the next token from the stream
        std::getline(ss, token, ',');

        if (token == "#") return nullptr; // If it's a null node
        TreeNode* node = new TreeNode(std::stoi(token)); // Create a new node with the value
        node->left = deserialize(ss.str().substr(ss.tellg())); // Deserialize left subtree
        node->right = deserialize(ss.str().substr(ss.tellg())); // Deserialize right subtree
        return node;
    };

};