#include <bits/stdc++.h>
using namespace std;

class TaskManager
{
    // hash map to map task id with {user, priority}
    unordered_map<int, pair<int, int>> taskMap;
    // priority queue to sort first by priority then task id:
    priority_queue<tuple<int, int, int>> pq;

public:
    TaskManager(vector<vector<int>> &tasks)
    {
        // initialises task manager: [userId, taskId, priority]
        for (auto &it : tasks)
        {
            int userId = it[0];
            int taskId = it[1];
            int priority = it[2];
            taskMap[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority)
    {
        // adds a task with the specified taskId and priority to the user with userId
        taskMap[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority)
    {
        // updates the priority of the existing taskId to newPriority
        int userId = taskMap[taskId].first;
        taskMap[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId});
    }

    void rmv(int taskId)
    {
        // removes the task identified by taskId from the system
        taskMap.erase(taskId);
    }

    int execTop()
    {
        // executes the task with the highest priority across all users
        // if tie: execute the one with the highest taskId
        // After executing, the taskId is removed from the system
        // Return the userId associated with the executed task
        // if no tasks available: return -1
        while (!pq.empty())
        {
            auto [priority, taskId, userId] = pq.top();
            if (taskMap.count(taskId) && taskMap[taskId].second == priority)
            {
                // valid task
                taskMap.erase(taskId);
                pq.pop();
                return userId;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

int main()
{

    return 0;
}