#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &chalk, int k)
{
    // students number=chalk.size() & starts from 0 & so on _ _ _
    // each studnet will take chalk[i] no of chalks until <k then replace
    int noOfStudents = chalk.size();
    int i = 0;
    while (chalk[i] <= k)
    {
        k = k - chalk[i]; // that chalk used
        if (i == noOfStudents - 1)
        {
            // last student then loop back to first student
            i = 0;
        }
        else
        {
            i++;
        }
    }
    // jaise hi less than hua
    return i; // return studnet no that will replace chalk
}

int chalkReplacer(vector<int> &chalk, int k)
{
    int noOfStudents = chalk.size();
    // calculate amount of chalk reqd for 1 complete round of students
    long long chalkReqd = 0;        //to prevent overflow
    for (int i = 0; i < noOfStudents; i++)
    {
        chalkReqd += chalk[i];
    }

    // for rounds so check for 1 itertaion by reducing k
    k = k % chalkReqd;

    // now iterate to check which student will replace chalk
    for (int i = 0; i < noOfStudents; i++)
    {
        if (chalk[i] > k)
        {
            // ie k is smaller
            return i;
        }
        k = k - chalk[i];
    }
    return 0;
}

int main()
{
    vector<int> chalk1 = {5, 1, 5};
    int k1 = 22;
    //  op:0
    cout << "\nBRUTE FORCE-> 1:The student number: " << brute_force(chalk1, k1) << " would have to replace chalk.";
    cout << "\n1:The student number: " << chalkReplacer(chalk1, k1) << " would have to replace chalk.";
    vector<int> chalk2 = {3, 4, 1, 2};
    int k2 = 25;
    //  op:1
    cout << "\nBRUTE FORCE-> 2:The student number: " << brute_force(chalk2, k2) << " would have to replace chalk.";
    cout << "\n2:The student number: " << chalkReplacer(chalk2, k2) << " would have to replace chalk.";
    return 0;
}