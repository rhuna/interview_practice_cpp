#include <cassert>
#include "serialize.cpp"


// This code defines a TreeNode structure and a Codec class for serializing and 
// deserializing a binary tree. The main function demonstrates how to use the 
// Codec class to serialize a sample binary tree and then deserialize it back 
// into a tree structure, verifying the values of the nodes. It also includes 
// an assertion to check that the deserialization process correctly reconstructs 
// the tree. Finally, it cleans up the allocated memory for the tree nodes.





int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree and print the serialized string
    Codec codec;
    std::string serialized = codec.serialize(root);
    std::cout << "Serialized tree: " << serialized << std::endl;

    // Deserialize the string back into a tree and print the values of the nodes
    TreeNode* deserializedRoot = codec.deserialize(serialized);
    std::cout << "Deserialized tree root value: " << deserializedRoot->val << std::endl;
    std::cout << "Deserialized tree left child value: " << deserializedRoot->left->val << std::endl;
    std::cout << "Deserialized tree right child value: " << deserializedRoot->right->val << std::endl;

    // Verify that the deserialized tree has the same structure and values as the original tree
    TreeNode* node = new TreeNode("root");
    node->left = new TreeNode("left");
    node->left->left = new TreeNode("left.left");
    node->right = new TreeNode("right");

    assert(codec.deserialize(codec.serialize(node))->left->left->sval == "left.left");

    // Clean up memory (delete the tree nodes)
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}