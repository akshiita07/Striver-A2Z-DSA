#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- 2LOOPS-     TIME:O(n^2)     SPACE-O(1)
void findMissingRepeatingNumbers_brute(vector<int> arr)
{
    vector<int> ans(2);
    int n = arr.size();

    // find which all nos must be there in array ie from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // actual:{1,2,3,4}
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == arr[j])
            {
                count++;
            }
        }
        // maintain whoose count==2 -->repeating
        if (count == 2)
        {
            ans[0] = i;
        }
        // compare actual with arr to check which is missing whoose count==0    -->missing
        if (count == 0)
        {
            ans[1] = i;
        }
    }
    cout << "The repeating & missing number is: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// BETTER-HASHING-     TIME:O(n)+O(n)==O(2n)     SPACE-O(n)-hash array
void findMissingRepeatingNumbers_better(vector<int> arr)
{
    vector<int> ans(2);
    int n = arr.size();
    // unordered_map<int,int> hashMap;         //no.count
    int hashArr[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        // hashMap[arr[i]]++;
        hashArr[arr[i]]++;
        // stores count
    }
    // iterate thru hashmap & find cout=2/0
    // for(int it=1;it<=n;it++){
    //     if(hashMap[it]==2){
    //         ans[0]=it;
    //     }
    //     if(hashMap[it]==0){
    //         ans[1]=it;
    //     }
    // }
    for (int i = 1; i <= n; i++)
    {
        if (hashArr[i] == 2)
        {
            ans[0] = i;
        }
        if (hashArr[i] == 0)
        {
            ans[1] = i;
        }
    }

    cout << "The repeating & missing number is: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// OPTIMAL-BASIC MATHS-     TIME:O(n)     SPACE-O(1)
void findMissingRepeatingNumbers_optimal1(vector<int> arr)
{
    vector<int> ans(2);
    int n = arr.size();
    int x, y = 0; // repeating,missing

    // eqn 1: sum of array  -   sum of first n nos
    int sn = ((n) * (n + 1)) / 2;
    int sum = 0;

    // eqn 2: sum of squares array  -   sum of squares first n nos
    int s2n = ((n) * (n + 1) * (2 * n + 1)) / 6;
    int squareSum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        squareSum += arr[i] * arr[i];
    }

    // subtract
    int eq1 = sum - sn;
    // subtract
    int eqAux = squareSum - s2n;

    // solve both eqns
    // x-y=eq1      x^2-y^2=(x-y)(x+y)=eqAux

    // find x+y
    int eq2 = eqAux / eq1;

    // x-y=eq1          x+y=eq2
    // add: 2x=eq1+eq2
    x = (eq1 + eq2) / 2; // repeating

    y = eq2 - x; // missing

    ans[0] = x;
    ans[1] = y;

    cout << "The repeating & missing number is: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// OPTIMAL-USING XOR CONCEPT-     TIME:O(2n)     SPACE-O(1)
void findMissingRepeatingNumbers_optimal2(vector<int> arr)
{
    vector<int> ans(2);
    int n = arr.size();
    int x = 0, y = 0; // repeating,missing

    // xor elem of array
    int xorArr = 0;
    // xor from 1 to n
    int xorN = 0;
    for (int i = 0; i < n; i++)
    {
        xorArr = xorArr ^ arr[i];
        xorN = xorN ^ (i + 1);
    }

    // now find total xor
    int xorTotal = xorArr ^ xorN;

    // find differentiating bit- ie first 1 from right
    int bitNo = 0;
    while (1)
    {
        // bitwise &
        if ((xorTotal & (1 << bitNo)) != 0)
        {
            // << left shift to find where does 1 occur?
            break;
        }
        bitNo++;
    }

    // classify numbers on basis of bitNo as 0 or 1
    int zeroSection = 0;
    int oneSection = 0;
    // for array
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & (1 << bitNo)) != 0)
        {
            // one club
            // xor numbers
            oneSection = oneSection ^ arr[i];
        }
        else
        {
            // zero club
            // xor numbers
            zeroSection = zeroSection ^ arr[i];
        }
    }
    // for 1 to N
    for (int i = 1; i <= n; i++)
    {
        if ((i & (1 << bitNo)) != 0)
        {
            // one club
            // xor numbers
            oneSection = oneSection ^ i;
        }
        else
        {
            // zero club
            // xor numbers
            zeroSection = zeroSection ^ i;
        }
    }

    // find whoose count==2
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == zeroSection)
        {
            count++;
        }
    }
    if (count == 2)
    {
        x = zeroSection; // missing no
        y = oneSection;  // repeating
    }
    else
    {
        y = zeroSection; // missing no
        x = oneSection;  // repeating
    }

    ans[0] = x;
    ans[1] = y;

    cout << "The repeating & missing number is: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    // vector<int> arr = {1, 2, 3, 2};          // Output :2 4
    vector<int> arr = {8, 4, 1, 6, 7, 2, 5, 8};
    // findMissingRepeatingNumbers_brute(arr);
    // findMissingRepeatingNumbers_better(arr);
    // findMissingRepeatingNumbers_optimal1(arr);
    findMissingRepeatingNumbers_optimal2(arr);

    return 0;
}