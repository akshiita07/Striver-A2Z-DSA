#include <bits/stdc++.h>
using namespace std;

// fnc      TIME:O(n)
int studentBookAssignment(vector<int> &arr, int n, int m, int maxPagesAllowed)
{
    // first student gets 1st book
    int noOfStudents = 1;
    int pagesAlloted = 0; // current pages allotted to student

    for (int i = 0; i < n; i++)
    {
        if ((pagesAlloted + arr[i]) <= maxPagesAllowed)
        {
            // give that book also to student
            pagesAlloted += arr[i];
        }
        else
        {
            // limit exceeded
            noOfStudents++;
            pagesAlloted = arr[i];
        }
    }
    return noOfStudents;
}

// BRUTE FORCE:     TIME:O(n)-->fnc*O(sum-max+1)-->loop
int brute_force(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        // no of students>no of books then  no possible min ans
        return -1;
    }
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0); // sum of all elements of arr
    for (int i = start; i <= end; i++)
    {
        int noOfStudents = studentBookAssignment(arr, n, m, i);

        if (noOfStudents == m)
        {
            // can allocate books to exactly m students
            return i;
        }
    }
    return -1;
}

// BINARY SEARCH:     TIME:O(n)-->fnc*O(log2(sum-max+1))-->loop
int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        // no of students>no of books then  no possible min ans
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0); // sum of all elements of arr

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int countStudents = studentBookAssignment(arr, n, m, mid);

        if (countStudents > m)
        {
            // zyada no of students
            low = mid + 1;
        }
        else
        {
            // less or equal no of students
            // check MIN possible ans
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;
    // output:113
    cout << "\nThe minimum possible assignment to give maxm possible pages to " << m << " students is: " << brute_force(arr, n, m);
    cout << "\nThe minimum possible assignment to give maxm possible pages to " << m << " students is: " << findPages(arr, n, m);

    return 0;
}