// TLE:
/*class AllOne {
public:
    unordered_map<string, int> hashMap;
    AllOne() { hashMap.empty(); }

    void inc(string key) {
        if (hashMap.find(key) == hashMap.end()) {
            // not present in map so incsert with count 1:
            hashMap[key] = 1;
        }
        // else present so increment its count:
        else {

            hashMap[key]++;
        }
    }

    void dec(string key) {
        // guaranteed present so decrement its count:
        hashMap[key]--;
        if (hashMap[key] == 0) {
            // remove it
            hashMap.erase(key);
        }
    }

    string getMaxKey() {
        int maxi = INT_MIN;
        string ans = "";
        // if not empty then only get
        if (!hashMap.empty()) {
            for (auto it : hashMap) {
                if (it.second > maxi) {
                    maxi = it.second;
                    ans = it.first;
                }
            }
        }
        return ans;
    }

    string getMinKey() {
        int mini = INT_MAX;
        string ans = "";
        // if not empty then only get
        if (!hashMap.empty()) {
            for (auto it : hashMap) {
                if (it.second < mini) {
                    mini = it.second;
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};
*/

class AllOne {
private:
    struct Node {
        int count;
        list<string> keys;
        Node* prev;
        Node* next;

        Node(int cnt) : count(cnt), prev(nullptr), next(nullptr) {}
    };

    unordered_map<string, int> count; // Map to store the count of each key
    unordered_map<int, Node*> nodes;  // Map to store the node for each count
    Node* head;                       // Dummy head node
    Node* tail;                       // Dummy tail node

public:
    AllOne() {
        head = new Node(0);       // Dummy head
        tail = new Node(INT_MAX); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        int newCount = ++count[key]; // Increment the count for the key

        if (nodes.find(newCount) == nodes.end()) {
            nodes[newCount] =
                new Node(newCount); // Create new node for new count
            Node* prevNode = head;

            // Find the right position to insert the new node
            while (prevNode->next != tail && prevNode->next->count < newCount) {
                prevNode = prevNode->next;
            }

            // Insert the new node into the linked list
            Node* currNode = nodes[newCount];
            currNode->next = prevNode->next;
            currNode->prev = prevNode;
            prevNode->next->prev = currNode;
            prevNode->next = currNode;
        }

        // Move the key from the old count to the new count
        if (newCount > 1) {
            int oldCount = newCount - 1;
            nodes[oldCount]->keys.remove(
                key); // Remove key from old count's list
            if (nodes[oldCount]->keys.empty()) {
                // Remove the old count node if it has no keys left
                Node* toDelete = nodes[oldCount];
                toDelete->prev->next = toDelete->next;
                toDelete->next->prev = toDelete->prev;
                nodes.erase(oldCount);
                delete toDelete; // Clean up memory
            }
        }

        nodes[newCount]->keys.push_back(
            key); // Add the key to the new count's list
    }

    void dec(string key) {
        int oldCount = --count[key]; // Decrement the count for the key
        nodes[oldCount + 1]->keys.remove(
            key); // Remove key from old count's list

        if (oldCount == 0) {
            count.erase(key); // Remove the key from the count map
        } else {
            if (nodes.find(oldCount) == nodes.end()) {
                nodes[oldCount] = new Node(
                    oldCount); // Create new node for the decremented count
                Node* prevNode = head;

                // Find the right position to insert the new node
                while (prevNode->next != tail &&
                       prevNode->next->count < oldCount) {
                    prevNode = prevNode->next;
                }

                // Insert the new node into the linked list
                Node* currNode = nodes[oldCount];
                currNode->next = prevNode->next;
                currNode->prev = prevNode;
                prevNode->next->prev = currNode;
                prevNode->next = currNode;
            }

            nodes[oldCount]->keys.push_back(
                key); // Add the key to the new count's list
        }

        // Clean up the node if it has no keys left
        if (nodes[oldCount + 1]->keys.empty()) {
            Node* toDelete = nodes[oldCount + 1];
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            nodes.erase(oldCount + 1);
            delete toDelete; // Clean up memory
        }
    }

    string getMaxKey() {
        return tail->prev != head ? *(tail->prev->keys.begin())
                                  : ""; // Return the first key in the max count
    }

    string getMinKey() {
        return head->next != tail ? *(head->next->keys.begin())
                                  : ""; // Return the first key in the min count
    }
};
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */