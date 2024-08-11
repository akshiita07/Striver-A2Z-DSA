#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

Node *convertArrToLL(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int countLen(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// TIME: O(n1*1)+O(n2*1)
// SPACE: O(n1)->put first list nodes in map
Node *using_hashing(Node *headA, Node *headB)
{
    // stores node & from which list it is
    unordered_map<Node *, int> hashMap; // TIME: O(1)->as unordered
    Node *temp1 = headA;
    // TIME: O(n1)
    while (temp1 != nullptr)
    {
        hashMap[temp1] = 1;
        temp1 = temp1->next;
    }
    Node *temp2 = headB;
    // TIME: O(n2)
    while (temp2 != nullptr)
    {
        // if we found exact same node in map then that is intersection point
        if (hashMap.find(temp2) != hashMap.end())
        {
            // ie found exact same node
            return temp2;
        }
        temp2 = temp2->next;
    }
    return NULL; // if no intersection point exists
}

// WITHOUT EXTRA SPACE: o(1) space
// TOTAL TIME: O(n1)+O(n2)+O(n1-n2)+O(n2)=O((2n1)+n2)
Node *getIntersectionNode(Node *headA, Node *headB)
{
    Node *t1 = headA;
    int len1 = countLen(headA); // TIME: O(n1)
    Node *t2 = headB;
    int len2 = countLen(headB); // TIME: O(n2)

    // check which one is longer LL
    if (len1 > len2) // TIME: O(n1-n2)
    {
        // move list1
        int d = len1 - len2;
        for (int i = 1; i <= d; i++)
        {
            t1 = t1->next;
        }
    }
    else if (len2 > len1) // TIME: O(n2-n1)
    {
        // move list2
        int d = len2 - len1;
        for (int i = 1; i <= d; i++)
        {
            t2 = t2->next;
        }
    }
    // now start comparing:
    // TIME: O(min(n1,n2))  ...shorter length ko traverse kiya
    while (t1 != nullptr && t2 != nullptr)
    {
        if (t1 == t2)
        {
            return t1;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return NULL;
}

// OPTIMAL APPROACH- REDUCE TIME
// TIME: O(n1+n2)
Node *optimal_approach(Node *headA, Node *headB)
{

    // if LL is empty?
    if (headA == nullptr || headB == nullptr)
    {
        // no collision possible
        return NULL;
    }
    Node *t1 = headA;
    Node *t2 = headB;

    while (t1!=t2)
    {
        t1 = t1->next;
        t2 = t2->next;
        // check for intersection:
        if(t1==t2){
            return t1;
        }
        // WHENEVER ONE OF THEM REACHES LAST NODE THEN NEXT SEND THEM TO OTHER HEAD
        if (t1 == nullptr)
        {
            t1 = headB;
        }
        if (t2 == nullptr)
        {
            t2 = headA;
        }
    }
    return t1;
}

int main()
{
    int arr1[] = {4, 1, 8, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node *node1 = convertArrToLL(arr1, n1);
    cout << "\nTraversing LL1: ";
    traverse(node1);

    int arr2[] = {5, 6, 1, 8, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *node2 = convertArrToLL(arr2, n2);
    cout << "\nTraversing LL2: ";
    traverse(node2);

    cout << "\nrunning fnc: ";
    // Node *ans = using_hashing(node1, node2);
    // Node *ans = getIntersectionNode(node1, node2);
    Node *ans = optimal_approach(node1, node2);

    cout << "\nTraversing from intersection point: ";
    traverse(ans);

    return 0;
}