/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    // TIME: O(n)->add in map + O(n)->find links == O(2n) where O(1)->unordered map
    // SPACE: O(n)->for hashMap + O(n)->for copy node to answer question!!
    Node *brute_force(Node *head)
    {
        // keep actual & new copy of node in hash map
        unordered_map<Node *, Node *> hashMap;
        Node *temp = head;
        // CREATE DUMMY NODES & STORE IN MAP
        while (temp != nullptr)
        {
            Node *newCopyNode = new Node(temp->data); // create new node
            hashMap[temp] = newCopyNode;              // store it
            temp = temp->next;
        }
        // make next & random pointers point to the correct nodes
        temp = head;
        while (temp != nullptr)
        {
            Node *copiedNode = hashMap[temp];
            // check where does temps next & random point to??
            copiedNode->next = hashMap[temp->next];
            copiedNode->random = hashMap[temp->random];

            temp = temp->next;
        }
        // head of copied list??
        temp = head;
        Node *newHead = hashMap[temp];

        return newHead;
    }

    // OPTIMISE WITHOUT USING HASH MAP:
    // store copied nodes in between
    // TIME: O(n)->insert after + O(n)->random pointer + O(n)->next pointer == O(3n)
    // SPACE: O(n)->to create new list that Ques demands
    void insertAfter(Node *node, int val)
    {
        // insert after node
        Node *newNode = new Node(val);
        newNode->next = node->next;
        node->next = newNode;
    }
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;

        // STEP1:: COPYING NODE
        while (temp != nullptr)
        {
            insertAfter(temp, temp->data);
            temp = temp->next->next; // move 2 places ahead
        }

        // STEP2:: CONNECTING RANDOM POINTERS
        // check where does actual elements next & random point to?
        temp = head;
        while (temp != nullptr)
        {
            Node *copiedNode = temp->next;
            Node *actualTempRandom = temp->random;
            Node *twoPlacesAhead = temp->next->next; // move 2 places ahead
            // copied node ka next must point to actual node ka next
            if (actualTempRandom != nullptr)
            {
                copiedNode->random = actualTempRandom->next;
            }
            else
            {
                copiedNode->random = nullptr;
            }
            temp = twoPlacesAhead;
        }

        //STEP3:: CONNECTING NEXT POINTERS
        Node *dummy = new Node(-1);
        Node *ptr = dummy;
        temp = head;
        while (temp != nullptr)
        {
            Node *copiedNode = temp->next;
            temp->next=temp->next->next;    //correct actual node links
            ptr->next=copiedNode;
            ptr=ptr->next;
            temp = temp->next;
        }
        Node *newHead = dummy->next;
        return newHead;
    }
};