class QueueImplementationUsingArrays
{
public:
    int size = 10; // extra space of O(size)
    int qu[size];
    int currentSize = 0; // keeps track how many elements in queue
    int start = -1;
    int end = -1;

    // functions:
    // TIME: O(1)
    void push(int x)
    {
        // check for capacity first:
        if (currentSize < size)
        {
            // possible
            if (start == -1)
            {
                start += 1;
            }
            // bring end to front if capacity is left & new element to be added
            end = (end + 1) % size;
            qu[start] = x;
            currentSize += 1;
        }
        else
        {
            cout << "\nSorry cannot push new elements as size unavailable";
            break;
        }
    }

    // TIME: O(1)
    int pop()
    {
        // REMOVE TOP MOST IE FRONT MAI JO HAI
        if (currentSize <= 0)
        {
            cout << "\nNo elements available to pop!";
            return 0;
        }
        else if (currentSize == 1)
        {
            // destroy last element & destroy queue
            int val = qu[start];
            start = -1;
            end = -1;
            currentSize -= 1;
            return val;
        }
        else
        {
            currentSize -= 1;
            int val = qu[start];
            start = (start + 1) % size; // if last element is to be popped out then
            return val;
        }
    }

    // TIME: O(1)
    int top()
    {
        // TOPMOST->1ST ELEMENT
        if (start == -1)
        {
            // no elements
            return 0;
        }
        return qu[start];
    }

    // TIME: O(1)
    int size()
    {
        return currentSize;
    }
};

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

class QueueImplementationUsingLinkedLists
{
public:
    Node *start = nullptr;
    Node *end = nullptr;
    int size = 0;

    // functions:
    // TIME: O(1)
    void push(int x)
    {
        Node *newNode = new Node(x);
        // check for capacity first:
        if (start == nullptr)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
        size += 1;
    }

    // TIME: O(1)
    void pop()
    {
        // REMOVE TOP MOST IE FRONT MAI JO HAI
        if (start == nullptr)
        {
            cout << "\nNo elements available to pop!";
            return;
        }
        Node *temp = start;
        delete temp;
        start = start->next;
        size -= 1;
    }

    // TIME: O(1)
    int top()
    {
        // TOPMOST->1ST ELEMENT
        if (start == nullptr)
        {
            // no elements
            return 0;
        }
        return start->data;
    }

    // TIME: O(1)
    int size()
    {
        return size;
    }
};