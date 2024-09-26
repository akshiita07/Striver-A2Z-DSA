#include <bits/stdc++.h>
using namespace std;

// add a new event if adding the event will not cause a double booking
// double booking happens when two events have some non-empty intersection
// represent event as [start, end)

class MyCalendar
{
public:
    // take a set to store the events
    set<pair<int, int>> events;

    MyCalendar()
    {
        //  Initializes the calendar object.
    }

    bool book(int start, int end)
    {
        // returns true if the event can be added to the calendar successfully without causing a double booking

        // check if overlaps with next (start1,end1) (start2,end2) ie start1<end2 and start2<end1
        auto next = events.lower_bound({start, end});
        if (next != events.begin())
        {
            auto prevEle = prev(next); // The event just before 'next'
            if (prevEle->second > start)
            {
                return false;
            }
        }
        if (next != events.end() && next->first < end)
        {
            return false;
        }

        // If no overlap, add the new event
        events.insert({start, end});
        return true;
    }
};

int main()
{
    MyCalendar *obj = new MyCalendar();
    bool param_1 = obj->book(10, 20);
    cout << "\n10,20: " << param_1;
    bool param_2 = obj->book(15, 25);
    cout << "\n15,25: " << param_2;
    bool param_3 = obj->book(20, 30);
    cout << "\n20,30: " << param_3;

    return 0;
}