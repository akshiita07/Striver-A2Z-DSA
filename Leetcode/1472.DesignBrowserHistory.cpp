class Node
{
public:
    string data;
    Node *next;
    Node *prev;

    Node(string data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory
{
public:
    Node *current;

    // TIME: O(1)
    BrowserHistory(string homepage)
    {
        // constructor home page
        current = new Node(homepage);
        cout << "\nCreated new node of url " << homepage;
    }

    // TIME: O(1)->just attaching new node
    void visit(string url)
    {
        // create new node
        Node *temp = new Node(url);
        current->next = temp;
        temp->prev = current;
        current = temp; // current place
        cout << "\nYou are in " << __ << " NOW Visit " << url;
        // delete all forward history
    }

    // TIME: O(steps)->how many steps go
    string back(int steps)
    {
        while (steps > 0)
        {
            if (current->prev != nullptr)
            {

                current = current->prev;
            }
            else
            {
                break;
            }
            steps--;
        }
        // if cannot go more backwards then return 1st home page
        return current->data;
    }

    // TIME: O(steps)->how many steps go
    string forward(int steps)
    {
        while (steps > 0)
        {
            if (current->next != nullptr)
            {

                current = current->next;
            }
            else
            {
                break;
            }
            steps--;
        }
        // if cannot go fwd then return current position
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */