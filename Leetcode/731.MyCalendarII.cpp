#include <bits/stdc++.h>
using namespace std;

// add a new event if adding the event will not cause a double booking
// double booking happens when two events have some non-empty intersection
// represent event as [start, end)

class MyCalendarTwo
{
public:
    // for storing events
    vector<pair<int, int>> events;
    // for booking events:
    vector<pair<int, int>> overlaps;

    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        // returns true if the event can be added to the calendar successfully without causing a triple booking

        //first check if overlaps
        for (const auto &overlap : overlaps)
        {
            if (max(start, overlap.first) < min(end, overlap.second))
            {
                return false; // Triple booking detected
            }
        }

        // check if overlaps with exisiting events
        for (const auto &event : events)
        {
            int overlap_start = max(start, event.first);
            int overlap_end = min(end, event.second);
            if (overlap_start < overlap_end)
            {
                overlaps.push_back({overlap_start, overlap_end});
            }
        }

        // Add event into events
        events.push_back({start, end});
        return true;
    }
};

int main()
{
    MyCalendarTwo *obj = new MyCalendarTwo();
    bool param_1 = obj->book(10, 20);
    cout << "\n10,20: " << param_1;
    bool param_2 = obj->book(50, 60);
    cout << "\n50,60: " << param_2;
    bool param_3 = obj->book(10, 40);
    cout << "\n10,40: " << param_3;
    bool param_4 = obj->book(5, 15);
    cout << "\n5,15: " << param_4;
    bool param_5 = obj->book(5, 10);
    cout << "\n5,10: " << param_5;

    return 0;
}