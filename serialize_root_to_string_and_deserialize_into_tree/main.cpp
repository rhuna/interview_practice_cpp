#include <cassert>
#include <iomanip>
#include "serialize.cpp"


// This code defines a TreeNode structure and a Codec class for serializing and 
// deserializing a binary tree. The main function demonstrates how to use the 
// Codec class to serialize a sample binary tree and then deserialize it back 
// into a tree structure, verifying the values of the nodes. It also includes 
// an assertion to check that the deserialization process correctly reconstructs 
// the tree. Finally, it cleans up the allocated memory for the tree nodes.

// Prints the tree sideways:
// right subtree at top, root in middle, left subtree at bottom
void printTree(TreeNode *root, int space = 0, int indent = 6)
{
    // Base case
    if (!root)
    {
        return;
    }

    auto safe = [](TreeNode* n){
        return n ? n->sval: "#";
    };

    // Increase spacing for the next level
    space += indent;

    // Print right subtree first
    printTree(root->right, space, indent);

    // Print current node
    std::cout << std::string(space - indent, ' ') << safe(root) << '\n';

    // Print left subtree
    printTree(root->left, space, indent);
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode("1");
    root->left = new TreeNode("2");
    root->right = new TreeNode("3");
    root->right->left = new TreeNode("4");
    root->right->right = new TreeNode("5");

    // Serialize the tree and print the serialized string
    Codec codec;
    std::string serialized = codec.serialize(root);
    std::cout << "Serialized tree: " << serialized << std::endl;

    // Deserialize the string back into a tree and print the values of the nodes
    TreeNode* deserializedRoot = codec.deserialize(serialized);
    std::cout << "Deserialized tree root value: " << deserializedRoot->sval << std::endl;
    std::cout << "Deserialized tree left child value: " << deserializedRoot->left->sval << std::endl;
    std::cout << "Deserialized tree right child value: " << deserializedRoot->right->sval << std::endl;
    std::cout << "Deserialized tree right->left child value: " << deserializedRoot->right->left->sval << std::endl;
    std::cout << "Deserialized tree right->right child value: " << deserializedRoot->right->right->sval <<std::endl;

    

    printTree(root);
    // Verify that the deserialized tree has the same struautry2293@outlook.cocture and values as the original tree
    TreeNode* node = new TreeNode("root");
    node->left = new TreeNode("left");
    node->left->left = new TreeNode("left.left");
    node->right = new TreeNode("right");
    node->right->left = new TreeNode("right.left");
    node->right->right = new TreeNode("right.right");

    assert(codec.deserialize(codec.serialize(node))->left->left->sval == "left.left");
    assert(codec.deserialize(codec.serialize(node))->right->right->sval == "right.right");

    // Clean up memory (delete the tree nodes)
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}