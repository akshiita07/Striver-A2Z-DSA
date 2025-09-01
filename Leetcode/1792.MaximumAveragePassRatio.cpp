#include <bits/stdc++.h>
using namespace std;

double passRatio(int pass, int total)
{
    // to calculate how much pass ratio will increase on adding a student:
    double newRatio = (double)(pass + 1) / (total + 1);
    double oldRatio = (double)pass / total;
    return newRatio - oldRatio;
}

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    // classes[i] = [passi who will pass the exam, totali no of students]
    // extraStudents guaranteed to pass exam
    // assign each extraStudents to a class st it maximizes the average pass ratio across all the classes
    // pass ratio=no of students that pass exam/total no of students
    // avg pass ratio= sum of pass ratio of ALL classes/total no of classes
    // Return the maximum possible average pass ratio

    // take priority queue that will store classes in order of adding extra student & change in ratio:
    priority_queue<pair<double, pair<int, int>>> maxHeap;

    // add all classes to pq:
    for (auto it : classes)
    {
        int pass = it[0];
        int total = it[1];
        double change = passRatio(pass, total);
        maxHeap.push({change, {pass, total}});
    }

    while (extraStudents > 0)
    {
        // take class from heap that has max change on adding student:
        auto [change, classInfo] = maxHeap.top();
        // remove it:
        maxHeap.pop();
        int pass = classInfo.first;
        int total = classInfo.second;
        // add new student:
        pass++;
        total++;
        // push updated class in heap:
        double newChange = passRatio(pass, total);
        maxHeap.push({newChange, {pass, total}});
        extraStudents--;
    }

    double totalRatio = 0.0;
    while (!maxHeap.empty())
    {
        auto [change, classInfo] = maxHeap.top();
        // remove it:
        maxHeap.pop();
        int pass = classInfo.first;
        int total = classInfo.second;
        totalRatio += (double)pass / total;
    }

    int totalNumberOfClasses = classes.size();
    return (double)totalRatio / totalNumberOfClasses;
}

int main()
{
    vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    int extraStudents = 2;
    cout << "\nMax possible avg is: " << maxAverageRatio(classes, extraStudents);

    return 0;
}
