#include <iostream>


class node{
public: 

    node(int val): val(val), next(nullptr) {}



    int val;
    node* next;
};

void printList(node *head)
{
    std::cout << "[";
    while (head != nullptr)
    {
        std::cout << head->val;
        if (head->next)
            std::cout << ",";
        head = head->next;
    }
    std::cout << "]\n";
}

node *addTwoNumbers(node *l1, node *l2)
{

    // Create a dummy node to act as the start of our result list.
    // This avoids edge cases when inserting the first node.
    node *dummy = new node(0);

    // 'current' will move along the result list as we build it.
    node *current = dummy;

    // This stores the carry from the previous addition (like in grade school math).
    int carry = 0;

    // Continue looping while:
    // - l1 still has digits
    // - OR l2 still has digits
    // - OR there is still a carry left (important for cases like 999 + 1)
    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {

        // If l1 exists, take its value, otherwise use 0
        // (handles uneven length lists)
        int val1 = (l1 != nullptr) ? l1->val : 0;

        // Same logic for l2
        int val2 = (l2 != nullptr) ? l2->val : 0;

        // Add the two digits plus any carry from the previous step
        int sum = val1 + val2 + carry;

        // Update carry:
        // If sum >= 10, carry will be 1 (or more if extended problem)
        carry = sum / 10;

        // The digit we store in the node is the remainder (0–9)
        int digit = sum % 10;

        // Create a new node with the computed digit
        current->next = new node(digit);

        // Move the current pointer forward to this new node
        current = current->next;

        // Move l1 forward if it exists
        if (l1)
            l1 = l1->next;

        // Move l2 forward if it exists
        if (l2)
            l2 = l2->next;
    }
    //print answer
   printList(dummy->next);

    // Return the actual head of the result list
    // (skip the dummy node)
    return dummy->next;
}

