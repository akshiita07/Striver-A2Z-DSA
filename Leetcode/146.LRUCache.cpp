// IMPORTANT:
#include <bits/stdc++.h>
using namespace std;

class bruteforce
{
public:
    int cap;
    deque<pair<int, int>> dq; // stores key-value pair in deque
    bruteforce(int capacity)
    {
        cap = capacity;
        dq.clear(); // initially
    }

    int get(int key)
    {
        for (auto it = dq.begin(); it != dq.end(); it++)
        {
            if (it->first == key)
            {
                int val = it->second;
                // change locations:
                // pop this element
                dq.erase(it);
                // push in front
                dq.push_front({key, value});
                // return answer
                return val;
            }
        }
        // not found:
        return -1;
    }

    void put(int key, int value)
    {
        // check if key already exists:then only update its value
        for (auto it = dq.begin(); it != dq.end(); it++)
        {
            if (it->first == key)
            {
                it->second = value;
                // change locations:
                // pop this element
                dq.erase(it);
                // push in front
                dq.push_front({key, value});
                return;
            }
        }
        // else: key not pre-exists
        // check if within capacity then push in front
        if (dq.size() < cap)
        {
            dq.push_front({key, value}); // push pair
        }
        else
        {
            // size>=cap
            // else: remove dq.back
            dq.pop_back();
            dq.push_front({key, value});
        }
        // add in front
    }
};

// optimised:USING DOUBLY LINKED LIST & MAP
class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k, int v)
    {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

// TIME: O(1)->when map takes O(1)
// SPACE: O()
class LRUCache
{
public:
    // 2 dummy nodes: head & tail
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> hashMap;
    int cap;

    // constructore:
    LRUCache(int capacity)
    {
        cap = capacity;
        hashMap.clear();
        // head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        // tail->next = nullptr;
    }

    void insertAfterHead(Node *temp)
    {
        Node* nextNode=head->next;
        temp->next = nextNode;
        nextNode->prev = temp;
        head->next = temp;
        temp->prev = head;
    }

    void deleteNode(Node *temp)
    {
        Node *prevNode = temp->prev;
        Node *nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        // delete temp; DO NOT DELETE AS WONT BE ABLE TO INSERT AS NEXT STEP
    }

    int get(int key)
    {
        // check if exists in map:
        if (hashMap.find(key) != hashMap.end())
        {
            Node *findNode = hashMap[key];
            int val = findNode->value;
            // delete this node
            deleteNode(findNode);
            // insert in front
            insertAfterHead(findNode);
            // ans:
            return val;
        }
        // if key is not present
        return -1;
    }

    void put(int key, int value)
    {
        // check if already exists
        if (hashMap.find(key) != hashMap.end())
        {
            // ie found key:
            Node *findNode = hashMap[key];
            // update value
            findNode->value = value;
            // delete this node
            deleteNode(findNode);
            // insert in front
            insertAfterHead(findNode);
        }
        else
        {
            // check capacity
            if (hashMap.size() == cap)
            {
                Node *newNode = tail->prev;
                // delete node from map also:
                hashMap.erase(newNode->key);
                // delete node at end (prev of tail)
                deleteNode(newNode);
            }
            // insert new node in front
            Node *newNode = new Node(key, value);
            hashMap[key] = newNode; // store node
            insertAfterHead(newNode);
        }
    }
};

int main()
{
    int capacity = 2;
    // bruteforce *obj = new bruteforce(capacity);
    LRUCache *obj = new LRUCache(capacity);
    obj->put(1, 1);
    cout << "\nDone put operation for 1,1";
    obj->put(2, 2);
    cout << "\nDone put operation for 2,2";
    int param_1 = obj->get(1);
    cout << "\nGet operation: " << param_1;
    obj->put(3, 3);
    cout << "\nDone put operation for 3,3";
    int param_2 = obj->get(2);
    cout << "\nGet operation: " << param_2;
    obj->put(4, 4);
    cout << "\nDone put operation for 4,4";
    int param_3 = obj->get(1);
    cout << "\nGet operation: " << param_3;
    int param_4 = obj->get(3);
    cout << "\nGet operation: " << param_4;
    int param_5 = obj->get(4);
    cout << "\nGet operation: " << param_5;

    return 0;
}