// IMPORTANT:
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    int useCounter; // counter
    Node *next;
    Node *prev;

    Node(int k, int v)
    {
        key = k;
        value = v;
        useCounter = 1; // start counting from 1
        next = nullptr;
        prev = nullptr;
    }
};

class LFUCache
{
public:
    int cap;
    int freq; // tracks which is least frequency node
    unordered_map<int, Node *> keyNodeMap;
    unordered_map<int, list<Node*>> frequencyMap;

    LFUCache(int capacity)
    {
        cap = capacity;
        freq = 0;
        keyNodeMap.clear();
        frequencyMap.clear();
    }

    void insertAfterHead(Node *temp)
    {
        // us node ke useCounter ctr pe push krdo node ko
        frequencyMap[temp->useCounter].push_front(temp);
        if(temp->useCounter==1){
            freq=1;
        }
    }

    void deleteNode(Node *temp)
    {
        frequencyMap[temp->useCounter].remove(temp);
        // if this index of freq becomes empty then remove it entirely
        if(frequencyMap[temp->useCounter].empty()==true){
            // erase that whole row:
            frequencyMap.erase(temp->useCounter);
            // now update the min freq
            if(freq==temp->useCounter){
                freq++;
            }
        }
    }

    void changeFreq(Node* temp){
        deleteNode(temp);
        temp->useCounter++;
        insertAfterHead(temp);
    }

    int get(int key)
    {
        // check if exists in map:
        if (keyNodeMap.find(key) != keyNodeMap.end())
        {
            Node *findNode = keyNodeMap[key];
            int val = findNode->value;
            // change frequnecy:
            changeFreq(findNode);
            // ans:
            return val;
        }
        // if key is not present
        return -1;
    }

    void put(int key, int value)
    {
        // check if already exists
        if (keyNodeMap.find(key) != keyNodeMap.end())
        {
            // ie found key:
            Node *findNode = keyNodeMap[key];
            // update value
            findNode->value = value;
            changeFreq(findNode);
        }
        else
        {
            // check capacity
            if (keyNodeMap.size() == cap)
            {
                Node *lastNode = frequencyMap[freq].back();
                // delete node from map also:
                keyNodeMap.erase(lastNode->key);
                // delete node at end (prev of tail)
                deleteNode(lastNode);
            }
            // insert new node in front
            Node *newNode = new Node(key, value);
            keyNodeMap[key] = newNode; // store node
            freq=1;
            insertAfterHead(newNode);
        }
    }
};

int main()
{
    int capacity = 2;
    LFUCache *obj = new LFUCache(capacity);
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
    int param_6 = obj->get(3);
    cout << "\nGet operation: " << param_6;
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