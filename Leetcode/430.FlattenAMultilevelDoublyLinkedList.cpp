/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        // base case:
        if (head == nullptr)
        {
            return head;
        }
        Node *temp = head;

        while (temp != nullptr)
        {
            Node *tempChild = temp->child;
            if (tempChild != nullptr)
            {
                Node *tempNext = temp->next;
                Node *child = flatten(tempChild);
                // check if child exists & change link
                temp->next = child;
                child->prev = temp;
                temp->child = nullptr; //it does not have any child now so nullptr
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                if (tempNext)
                {
                    temp->next = tempNext;
                    tempNext->prev = temp;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};