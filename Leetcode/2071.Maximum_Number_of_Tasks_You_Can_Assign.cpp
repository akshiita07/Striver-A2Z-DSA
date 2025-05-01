#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &tasks, vector<int> &workers, int pills, int strength)
{
    // n tasks
    int n = tasks.size();
    // task[i] denotes strength reqd to complete ith task

    // m workers
    int m = workers.size();
    // worker[i] denotes strength of ith worker

    // worker assigned with 1 task only if worker[j]>=task[i]

    // pills increases the strength of the worker by 'strength' amount
    // each worker can get MAX only 1 pill not more

    // return the maximum number of tasks that can be completed

    // sort tasks and workers in inc order: assign weakest worker to weakest task-> greedy
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int ans = 0;
    // loop thru min of n or m
    for (int i = 1; i <= min(n, m); i++)
    {
        // take iterators for indices:
        int taskIndex = 0;
        int workerIndex = 0;
        int pillsUsed = 0;
        int tasksDone = 0;
        // try assigning first i tasks to workers:
        while (taskIndex < i && workerIndex < m)
        {
            // check strength:
            if (workers[workerIndex] >= tasks[taskIndex])
            {
                tasksDone++;
                taskIndex++;
                workerIndex++;
            }
            // try with pill:
            else if (pillsUsed < pills && workers[workerIndex] + strength >= tasks[taskIndex])
            {
                tasksDone++;
                taskIndex++;
                workerIndex++;
                pillsUsed++;
            }
            // nothing possible
            else
            {
                workerIndex++;
            }
        }
        ans = max(ans, tasksDone);
    }
    return ans;
}

int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                  int strength)
{
    // n tasks
    int n = tasks.size();
    // task[i] denotes strength reqd to complete ith task

    // m workers
    int m = workers.size();
    // worker[i] denotes strength of ith worker

    // worker assigned with 1 task only if worker[j]>=task[i

    // pills increases the strength of the worker by 'strength' amount
    // each worker can get MAX only 1 pill not more

    // return the maximum number of tasks that can be completed

    // binary search+greedy
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    auto check = [&](int mid) -> bool
    {
        int p = pills;
        // Ordered set of workers
        multiset<int> ws;
        for (int i = m - mid; i < m; i++)
        {
            ws.insert(workers[i]);
        }
        // Enumerate each task from largest to smallest
        for (int i = mid - 1; i >= 0; i--)
        {
            // If the largest element in the ordered set is greater than or
            // equal to tasks[i]
            if (auto it = prev(ws.end()); *it >= tasks[i])
            {
                ws.erase(it);
            }
            else
            {
                if (!p)
                {
                    return false;
                }
                auto rep = ws.lower_bound(tasks[i] - strength);
                if (rep == ws.end())
                {
                    return false;
                }
                --p;
                ws.erase(rep);
            }
        }
        return true;
    };
    int ans = 0;
    int left = 1;
    int right = min(n, m);
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> tasks = {10, 15, 30};
    vector<int> workers = {0, 10, 10, 10, 10};
    int pills = 3;
    int strength = 10;
    cout << "\nbrute_force Maximum number of tasks that can be completed: " << brute_force(tasks, workers, pills, strength);
    cout << endl;
    cout << "\nMaximum number of tasks that can be completed: " << maxTaskAssign(tasks, workers, pills, strength);
    return 0;
}