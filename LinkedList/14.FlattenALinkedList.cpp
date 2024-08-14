// (1) ‘next’ which points to the next node in the list
// (2) ‘child’ pointer to a linked list where the current node is the head.
// LL IS VERTICALLY SORTED!

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

// BRUTE FORCE:
// let n next & m cilds
// TIME: O(n*m)->for next & child ptr push into list + O(log2(n*m))->to sort + O(n*m)->to convert == o(2n*m +log2(n*m))
// SPACE: O(2(n*m))->array holding n*m complexity & then a linked list created holding these elements
// ADD ALL ELEMENTS IN ANOTHER ARRAY
Node *convertVectorToVerticalLL(vector<int> listArray)
{
    Node *head = new Node(listArray[0]);
    Node *mover = head;
    for (int i = 1; i < listArray.size(); i++)
    {
        Node *temp = new Node(listArray[i]);
        mover->child = temp;
        mover = temp;
    }
    return head;
}
Node *brute_force(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    vector<int> listArray;
    Node *tempNext = head;
    while (tempNext != nullptr)
    {
        Node *tempChild = tempNext;
        // move to last index
        while (tempChild != nullptr)
        {
            // ADD ELEMENTS IN ARRAY
            listArray.push_back(tempChild->data);
            tempChild = tempChild->child;
        }
        // now make child point to next
        tempNext = tempNext->next;
    }

    // NOW SORT THIS ARRAY
    sort(listArray.begin(), listArray.end());

    // CONVERT THIS SORTED ARRAY INTO VERTICAL LL IE CHILD PTR
    Node *newLL = convertVectorToVerticalLL(listArray);

    return newLL;
}

// OPTIMAL:
// merge 2 lists in child format (vertical format)
// TIME: O(n1+n2)->traversing both lists
Node *merge2Lists(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1); // dummy node with value=-1;
    Node *ptr = dummyNode;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
        {
            ptr->child = list1;
            ptr = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->child = list2;
            ptr = list2;
            list2 = list2->next;
        }
        ptr->next = nullptr;
    }
    // for remaining elements
    if (list1)
    {
        ptr->child = list1;
    }
    if (list2)
    {
        ptr->child = list2;
    }
    head = dummyNode->child;
    return head;
}
// n no of next nodes
// m no of child nodes
// TIME: O(n)->going n hoizontal nodes * O(m1+m2)->calling merge on it on child m nodes == O(n*2m)
// SPACE: O(1) BUT using recursive stack space
Node *flattenLinkedList(Node *head)
{
    // base case:
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // merge multiple lists:
    // from the end take 2 lists at a time & merge them : USE BACKTRACKING!
    // USING RECURSION
    Node *mergedHead = flattenLinkedList(head->next);
    return merge2Lists(head, mergedHead);
}
