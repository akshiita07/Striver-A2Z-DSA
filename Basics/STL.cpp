#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// PAIRS
void utility_lib_pairs()
{
    // TO STORE 2 INTS 7,27
    pair<int, int> var_name = {7, 27};
    cout << var_name.first << " " << var_name.second << endl;

    // NESTING PAIRS:
    pair<int, pair<int, int>> p = {12, {2, 27}};
    cout << p.first << " " << p.second.first << " " << p.second.second << endl;

    // TO STORE ARRAY:
    pair<int, int> arr[] = {{12, 8}, {7, 1}, {27, 7}};
    cout << arr[1].first << " " << arr[1].second << endl;
}

// VECTOR
void vectorExp()
{
    // CREATE AN EMPTY VECTOR CONTAINER
    vector<int> v;
    // PUSH ELEMENTS INSIDE VECTOR
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    // SIMILARLY FASTER METHOD: emplace_back
    v.emplace_back(40);

    // PRINT SIZE OF THIS VECTOR: NO OF ELEMENTS INSIDE VECTOR
    cout << "No of elements in vector are: " << v.size() << endl;

    // TO GET FIRST ELEMENT
    cout << "First element is: " << v.front() << endl;
    // TO GET LAST ELEMENT
    cout << "Last element is: " << v.back() << endl;

    // PRINT VECTOR USING FOR-EACH LOOP
    for (auto x : v)
    {
        cout << x << " ";
    }

    // CREATE A VECTOR OF SPECIFIC SIZE & INITIALISE IT
    vector<int> v1(5, 100); //{100,100,100,100,100}
    for (auto x : v1)
    {
        cout << x << " ";
    }
    // BY DEFAULT IT IS INITIALISED WITH 0
    vector<int> v2(3); //{0,0,0}
    for (auto x : v2)
    {
        cout << x << " ";
    }

    // TO COPY VECTOR v INTO ANOTHER VECTOR z:
    vector<int> z(v);

    // ITERATORS

    // v.begin() prints MEMORY LOCATION of first element
    vector<int>::iterator it = v.begin(); // v={10 20 30 40}
    cout << "v.begin() prints first element after dereferencing: " << *it << endl;
    it += 2;
    cout << "it+=2: " << *it << endl;

    // v.end() prints MEMORY LOCATION AFTER LAST element
    vector<int>::iterator it2 = v.end() - 1; // v={10 20 30 40}
    cout << "v.end()-1 prints last element after dereferencing: " << *it2 << endl;
    it2 -= 2;
    cout << "it2-=2: " << *it2 << endl;

    // v.rbegin() prints MEMORY LOCATION of LAST element
    vector<int>::reverse_iterator it3 = v.rbegin();                                 // v={10 20 30 40}
    cout << "v.rbegin() prints LAST element after dereferencing: " << *it3 << endl; // 40
    it3 += 2;
    cout << "it3+=2: " << *it3 << endl; // 20

    // v.rend() prints MEMORY LOCATION BEFORE FIRST element
    vector<int>::reverse_iterator it4 = v.rend() - 1;                                // v={10 20 30 40}
    cout << "v.rend()-1 prints first element after dereferencing: " << *it4 << endl; // 10
    it4 -= 2;
    cout << "it4-=2: " << *it4 << endl; // 30

    // PRINT VECTOR USING ITERATOR
    for (vector<int>::iterator it5 = v.begin(); it5 != v.end(); it5++)
    {
        cout << *(it5) << " ";
    }
    // using auto that automatically declares data type:
    for (auto it6 = v.begin(); it6 != v.end(); it6++)
    {
        cout << *(it6) << " ";
    }

    // TO DELETE 1 SINGLE ELEMENT   .erase(starting address)
    cout << "\nAfter removing v.begin() ie 1st element of v: \n";
    v.erase(v.begin()); // after v:20,30,40
    for (auto it6 = v.begin(); it6 != v.end(); it6++)
    {
        cout << *(it6) << " ";
    }

    // TO DELETE SOME ELEMENTS: .erase(starting address,till end address ie not included)
    cout << "\nAfter removing from z.begin() to z.end()-2 of z: \n";
    z.erase(z.begin(), z.end() - 2); // z:10,20,30,40
    for (auto it6 = z.begin(); it6 != z.end(); it6++)
    {
        cout << *(it6) << " "; // 30,40
    }

    // pop_back to delete last element  v1:{100,100,100,100,100}
    v1.pop_back();
    cout << "\nAfter pop_back of v1 remaining: \n";
    for (int x : v1)
    {
        cout << x << " "; // v1:{100,100,100,100}
    }

    // TO INSERT 1 SINGLE ELEMENT
    // z:30,40
    cout << "\nAfter inserting from z.begin() value 80: \n";
    z.insert(z.begin(), 80);

    // TO INSERT SOME ELEMENTS
    cout << "\nAfter inserting from z.begin() value 70 for 3 times: \n";
    z.insert(z.begin() + 1, 3, 70);

    for (auto it6 = z.begin(); it6 != z.end(); it6++)
    {
        cout << *(it6) << " ";
    }

    // VECTOR OF PAIRS
    vector<pair<int, int>> vpair;
    vpair.push_back({12, 8});  // in push_back use {} for pairs
    vpair.emplace_back(7, 27); // in emplace_back no need to use {} for pairs
}

// LIST
void listExp()
{
    // TO CREATE:
    list<int> l;
    l.push_back(10);
    l.emplace_back(20);
    // l:10,20
    l.push_front(2);
    // l:2,10,20
    cout << "Size/ No of elements of list are: " << l.size() << endl;

    l.erase(l.begin()); // l:10,20
    l.pop_front();      // l:20

    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *(it) << " ";
    }
}

// DEQUEUE
void dequeueExp()
{
    // CREATE NEW DQ
    deque<int> d;
    d.push_back(2);
    d.emplace_back(4);
    d.push_front(0); // d:0,2,4
    d.push_front(8); // d:8,0,2,4

    d.pop_back();  // d:8,0,2
    d.pop_front(); // d:0,2

    for (auto it = d.begin(); it != d.end(); it++)
    {
        cout << *(it) << " ";
    }
}

// STACK- lifo
void stackExp()
{
    // CREATE NEW STACK
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(6);
    st.push(8);
    st.emplace(10);

    st.pop();

    cout << "The topmost element of stack: " << st.top() << endl;
    cout << "The size/no of elements in stack: " << st.size() << endl;
    cout << "Is stack empty? " << st.empty() << endl; // 0:false 1:true
}

// QUEUE: FIFO
void queueExp()
{
    // create
    queue<int> q;
    // add elements
    q.push(2);
    q.push(4);
    q.push(6);
    q.emplace(8);
    // q: 2 4 6 8

    cout << "The no of elements in queue -size= " << q.size() << endl; // 4
    cout << "The FRONTmost element in queue= " << q.front() << endl;   // 2
    cout << "The LASTmost element in queue= " << q.back() << endl;     // 8

    // remove elements that entered first!
    q.pop();
}

// PRIORITY QUEUE: max heap-largest element at top / min heap-smallest element at top
void priorQueue()
{
    // create max heap by deafult
    priority_queue<int> pq;
    // add elements
    pq.push(2);
    pq.push(8);
    pq.push(10);
    pq.push(5);
    pq.emplace(3);
    pq.emplace(12);
    // pq: top 12  10  8  5  3   2        btm

    // remove topmost element ie largest!
    pq.pop(); // removes 12

    cout << "The no of elements in prior queue MAX_HEAP -size= " << pq.size() << endl; // 5
    cout << "The TOPmost element in prior queue MAX_HEAP= " << pq.top() << endl;       // 10- MAX ELE

    // CREATE MIN HEAP- STORES SMALLEST ELEMENT AT TOP
    priority_queue<int, vector<int>, greater<int>> pq2; // this changes
    // add elements
    pq2.push(2);
    pq2.push(8);
    pq2.push(10);
    pq2.push(5);
    pq2.emplace(3);
    pq2.emplace(12);
    // pq2: top 2 3 5 8 10 12    btm

    // remove topmost element ie smallest!
    pq2.pop(); // removes 2

    cout << "The no of elements in prior queue MIN_HEAP -size= " << pq2.size() << endl; // 5
    cout << "The TOPmost element in prior queue MIN_HEAP= " << pq2.top() << endl;       // 3- MAX ELE
}

// SET: UNQIUE+SORTED ORDER STORAGE
void setExp()
{
    // create
    set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(10); // it still stores 10 only once
    s.insert(3);
    s.insert(8);
    s.emplace(12);
    // order: top 3 5 8 10 12   btm
    cout << "No of elements in set: " << s.size() << endl;

    // to find a specific element
    auto it = s.find(4);  // not found
    auto it2 = s.find(8); // found

    auto it3 = s.erase(12); // order: top 3 5 8 10  btm

    auto it4 = s.count(4);
    cout << "Is 4 present bool: " << it4 << endl;
    auto it5 = s.count(8);
    cout << "Is 8 present bool: " << it5 << endl;
}

// MULTI SET: NOT UNQIUE+SORTED ORDER STORAGE
// CAN STORE MULTIPLE OCCURENCES-> NOT UNIQUE
void multiSetExp()
{
    multiset<int> ms;
    ms.insert(3);
    ms.insert(2);
    ms.insert(3);
    ms.emplace(8);
    ms.emplace(3);
    // order: top  2 3 3 3 8     btm        stores non unique elements also

    // but if i erase element then all occurrences of that element r removed
    ms.erase(3);
    // order: top  2  8     btm

    // but if i erase ADDRESS then that specific element is only removed
    ms.erase(ms.find(3));
    // order: top  2 3 3 8     btm          only first found occurrence if 3 is removed.
}

// UNORDERED SET: UNQIUE+NOT SORTED ORDER STORAGE
// STORES IN A RANDOM ORDER
void unordSetExp()
{
    unordered_set<int> us;
    us.insert(12);
    us.insert(2);
    us.insert(7);
    us.insert(7); // does not store duplicates
    us.insert(3);
    us.emplace(9);
    us.emplace(10);
    // random order store

    // all operations take O(1) time
    // upper_bound & lower_bound fncs DO NOT WORK
}

// MAP - STORES KEY:VALUE PAIRS
void mapExp()
{
    // KEYS R STORED IN SORTED ORDER

    // ways to create
    map<int, int> m;
    map<int, pair<int, int>> m1;
    map<pair<int, int>, int> m2;

    // to assign value name[map]=value
    m[1] = 2;
    // to insert/emblace value
    m.insert({2, 4});
    m.insert({4, 16});
    m.emplace(3, 12);

    // to insert in pair<>
    m2.insert({{3, 9}, 6});
    m2.emplace(make_pair(4, 8), 2); // when u have to make_pair within emplace

    // check if a key is present in map or not?
    cout << "Is key 5 present in map? bool: " << m.count(5) << endl;
    cout << "Is key 3 present in map? bool: " << m.count(3) << endl;

    // to remove a key from map
    m.erase(1); // removed {1,2} pair from map

    // to print: for-each loop
    for (auto x : m)
    {
        cout << "m: Key: " << x.first << " Value: " << x.second << endl;
    }
    // to print: for-each loop
    for (auto x : m2)
    {
        cout << "m2: Key val1: " << x.first.first << " Key val2: " << x.first.second << " Value: " << x.second << endl;
    }
}

// MULTIMAP- STORES NON-UNIQUE duplicate KEYs ALSO   + sorted order
void multiMapExp()
{
    multimap<int, int> mp;
    mp.insert({1, 3});
    mp.insert({2, 4});
    mp.insert({5, 1});
    mp.insert({1, 5});

    // print
    for (auto x : mp)
    {
        cout << "Key: " << x.first << " Value: " << x.second << endl;
    }
}

// UNORDERED MAP- STORES UNIQUE KEYs IN RANDOMIZED order
void unorMapExp()
{
    unordered_map<int, int> um;
    um.insert({1, 3});
    um.insert({2, 4});
    um.insert({5, 1});
    um.insert({3, 9});

    // print
    for (auto x : um)
    {
        cout << "Key: " << x.first << " Value: " << x.second << endl; // random order ie NOT SORTED!
    }
}

// ALGORITHMS:
void algoExp()
{
    vector<int> v = {2, 9, 5, 3, 12};
    // SORT AN ARRAY
    for (auto x : v)
    {
        cout << x << " ";
    }

    // to sort whole vector
    // sort(v.begin(), v.end());

    // to sort only a specific part
    // sort(v.begin()+2, v.end());     //from 5 to 12 sort

    // to sort in decreasing order- add a comparator ie greater<int>
    sort(v.begin(), v.end(), greater<int>());

    cout << "\nAfter sorting \n";
    for (auto x : v)
    {
        cout << x << " ";
    }
}

// comparator for fnc algoExp2()
bool mycomp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {
        // sort by dec order of 1st
        if (p1.first > p2.first)
        {
            return true; // dec order
        }
        else
        {
            return false;
        }
    }
    if (p1.second < p2.second)
    {
        // correct order
        return true;
    }
    if (p1.second > p2.second)
    {
        // INcorrect order
        return false;
    }
}

void algoExp2()
{
    pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};
    // create our own comparator that returns bool & sorts in inc order of 2nd value..if 2nd value is same then in decreasing order of 1st value

    // SORT AN ARRAY
    for (auto x : arr)
    {
        cout << x.first << " "<< x.second<<endl ;
    }

    sort(arr, arr+3, mycomp);

    cout << "\nAfter sorting \n";
    for (auto x : arr)
    {
        cout << x.first << " "<< x.second<<endl ;
    }
}

int main()
{
    // utility_lib_pairs();
    // vectorExp();
    // listExp();
    // dequeueExp();
    // stackExp();
    // queueExp();
    // priorQueue();
    // setExp();
    // multiSetExp();
    // unordSetExp();
    // mapExp();
    // multiMapExp();
    // unorMapExp();

    // algoExp();
    algoExp2();

    return 0;
}