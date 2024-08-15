class StackImplementationUsingArrays
{
public:
    int top = -1;
    int size = 10; // NOT DYNAMIC IN NATURE!! SIZE:O(size)
    int st[size];

    // TIME: O(1)
    void push(int x)
    {
        if (top > size)
        {
            cout << "\nCannot add more elements!";
            break;
        }
        top += 1;
        st[top] = x;
    }

    // TIME: O(1)
    int top()
    {
        if (top == -1)
        {
            cout << "\nNo elements in stack";
            return 0;
        }
        return st[top];
    }

    // TIME: O(1)
    int pop()
    {
        // DELETE TOPMOST ELEMENT
        if (top == -1)
        {
            cout << "\nNo elements in stack";
            break;
        }
        top -= 1;
        return st[top];
    }

    // TIME: O(1)
    int size()
    {
        return (top + 1);
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
class StackImplementationUsingLinkedLists
{
public:
    Node *top;
    int size=0;
    // SPACE:O(1)-> NO EXTRA SPACE..ONLY ONES REQD

    // TIME: O(1)
    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size+=1;
    }

    // TIME: O(1)
    int top()
    {
        if (top != nullptr)
        {
            return top->data;
        }
        return -1;
    }

    // TIME: O(1)
    void pop()
    {
        // DELETE TOPMOST ELEMENT
        if (top == nullptr)
        {
            cout << "\nNo elements in stack";
            break;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        size-=1;
    }

    // TIME: O(1)
    int size()
    {
        return size;
    }
};