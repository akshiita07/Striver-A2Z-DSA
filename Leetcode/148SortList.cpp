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

// TIME: O(n)->to push elemnets in array + O(log2(n))->to sort array + O(n)->changing elements of LL == O(2n+log2(n))
// SPACE: O(n)->elements in vector
Node *brute_force(Node *head)
{
    vector<int> list;
    Node* temp=head;
    while(temp!=nullptr){
        list.push_back(temp->data);
        temp=temp->next;
    }
    sort(list.begin(),list.end());

    // add these elem back in ll
    temp=head;
    int i=0;
    while(temp!=nullptr){
        temp->data=list[i];
        i++;
        temp=temp->next;
    }
    return head;    
}

// IMPLEMENT MERGE SORT WITHIN LINKED LIST ITSELF
// TIME: O(n1+n2)->merge2LL * O(log2(n))->height of tree  * O(n/2)->to find middle == O(log2(n)*n + n/2) == O(n*log(n))
// SPACE: O(1)-> no extra space --> IN PLACE SORTING
Node* merge2LL(Node* list1,Node* list2){
    Node* dummy=new Node(-1);
    Node* ptr=dummy;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data<=list2->data){
            ptr->next=list1;
            ptr=list1;
            list1=list1->next;
        }else{
            ptr->next=list2;
            ptr=list2;
            list2=list2->next;
        }
    }
    // remaining elments:
    if(list1){
        ptr->next=list1;
    }
    if(list2){
        ptr->next=list2;
    }
    Node* head=dummy->next;
    return head;
}
Node* middleUsingTortoiseHare(Node*head){
    Node* slow=head;
    Node* fast=head->next;
    // in case of even -> we require first middle
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node *optimalApproach(Node *head)
{
    // base case:when left with single elements
    if(head==nullptr || head->next==nullptr){
        // if no element/single elemnet then sorted in itself
        return head;
    }
    // find middle of LL using tortoise & hare approach
    Node* mid=middleUsingTortoiseHare(head);
    Node* left=head;
    // right LL will be next of mid
    Node* right=mid->next;

    // now to break this list: mid's next must point to null
    mid->next=nullptr;

    left=optimalApproach(left);       //from head
    right=optimalApproach(right);     //from mid->next
    return merge2LL(left,right);
}

int main()
{
    int arr[] = {1, 0, 2, 1, 0, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    // Node* sortedNode=brute_force(node);
    Node* sortedNode=optimalApproach(node);
    cout<<"\nAfter sorting LL is: ";
    traverse(sortedNode);

    return 0;
}