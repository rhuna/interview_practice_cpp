#include "node.hpp"


class XORLinkedList
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;

    void add(int val)
    {
        Node *node = new Node(val);

        if (!head)
        {
            head = tail = node;
        }
        else
        {
            node->both = reinterpret_cast<uintptr_t>(tail);
            tail->both = reinterpret_cast<uintptr_t>(XOR(reinterpret_cast<Node *>(tail->both), node));
            tail = node;
        }
    }

    Node *get(int index)
    {
        Node *current = head;
        Node *prev = nullptr;

        int i = 0;

        while (current && i < index)
        {
            Node *next = XOR(prev, reinterpret_cast<Node *>(current->both));
            prev = current;
            current = next;
            i++;
        }

        return current;
    }
};