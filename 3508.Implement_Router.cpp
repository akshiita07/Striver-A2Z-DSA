#include <bits/stdc++.h>
using namespace std;

class Router
{
    // source-> machine that generates the packet
    // destination-> target machine
    // timestamp-> time at which packet arrived
    struct Packet
    {
        int source;
        int destination;
        int timestamp;
    };

    int memoryLimit;
    // store packets in FIFO order
    deque<Packet> q;
    // to detect duplicates in set:
    unordered_set<string> packetSet;
    // destination -> sorted timestamps
    unordered_map<int, vector<int>> destMap;

    string makeKey(int s, int d, int t)
    {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

public:
    Router(int memoryLimit)
    {
        // memoryLimit-> maxm no of packets that router can store
        // Initialize Router with memoryLimit
        // remove old packets to free up space for a new packet
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        // return true if packet is successfully added ie NOT a duplicate ie same values of source, destination, timestamp do not exist
        string key = makeKey(source, destination, timestamp);

        // Check duplicate
        if (packetSet.count(key))
        {
            return false;
        }

        // If full then delete old one:
        if ((int)q.size() == memoryLimit)
        {
            Packet old = q.front();
            q.pop_front();
            string oldKey = makeKey(old.source, old.destination, old.timestamp);
            packetSet.erase(oldKey);

            auto &vec = destMap[old.destination];
            auto it = lower_bound(vec.begin(), vec.end(), old.timestamp);
            if (it != vec.end() && *it == old.timestamp)
            {
                vec.erase(it);
            }
        }

        Packet p = {source, destination, timestamp};
        q.push_back(p);
        packetSet.insert(key);
        destMap[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket()
    {
        // foward packet in fifo order
        // remove packet from storage & return its array else {}
        if (q.empty())
        {
            return {};
        }

        Packet p = q.front();
        q.pop_front();

        string key = makeKey(p.source, p.destination, p.timestamp);
        packetSet.erase(key);

        auto &vec = destMap[p.destination];
        auto it = lower_bound(vec.begin(), vec.end(), p.timestamp);
        if (it != vec.end() && *it == p.timestamp)
        {
            vec.erase(it);
        }

        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime)
    {
        // Returns the number of packets currently stored in the router at specific destination & having timestamps in the inclusive range [startTime, endTime]
        if (!destMap.count(destination))
        {
            return 0;
        }
        auto &vec = destMap[destination];
        auto lo = lower_bound(vec.begin(), vec.end(), startTime);
        auto hi = upper_bound(vec.begin(), vec.end(), endTime);
        return hi - lo;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

int main()
{

    return 0;
}