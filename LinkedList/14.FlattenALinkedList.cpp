// (1) ‘next’ which points to the next node in the list
// (2) ‘child’ pointer to a linked list where the current node is the head.

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *flattenLinkedList(Node *head)
{
    Node *tempNext = head;
    Node *tempChild = head;
    while (tempNext != nullptr)
    {
        // move to last index
        Node* nextTemp=tempNext->next;
        while (tempChild->next != nullptr)
        {
            tempChild = tempChild->child;
        }
        // now make child point to next
        tempChild->next = tempNext->next;
        tempNext =nextTemp;
    }
    return head;
}
