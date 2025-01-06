#include <bits/stdc++.h>
using namespace std;

vector<int> minOperations(string boxes)
{
    int number_of_boxes = boxes.length();
    // boxes[i]=0 if contains no ball
    // boxes[i]=1 if contains 1 ball
    // move a ball from a box to an adjacent box
    // box i and j are adjacent if abs(i - j) == 1
    vector<int> answer(number_of_boxes, 0);
    // answer[i] is the minimum number of operations needed to move all the balls to the ith box

    // for each box i
    int cnt = 0;
    int operations = 0;
    // left to right
    for (int i = 0; i < number_of_boxes; i++)
    {
        answer[i] = operations;
        cnt += boxes[i] - '0';
        operations += cnt;
    }

    cnt = 0;
    operations = 0;
    // right to left
    for (int i = number_of_boxes - 1; i >= 0; i--)
    {
        answer[i] += operations;
        cnt += boxes[i] - '0';
        operations += cnt;
    }
    return answer;
}

int main()
{
    string boxes = "110";
    vector<int> ans = minOperations(boxes); //[1,1,3]
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}