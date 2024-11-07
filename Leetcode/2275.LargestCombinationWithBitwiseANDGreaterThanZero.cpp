#include <bits/stdc++.h>
using namespace std;

int largestCombination(vector<int> &candidates)
{
    int maxLength=0;
    int n=candidates.size();    
    // as numbers can be large upto 2^30 so check from 0 to 29
    for(int bit=0;bit<30;bit++){
        int cnt=0;      //to count how many numbers in candidates have a bit as 1(set bit)
        for(int i=0;i<n;i++){
            if(candidates[i] & (1<<bit)){   //checks if the bit position in num is set to 1
                cnt++;
            }
        }
        maxLength=max(maxLength,cnt);
    }
    return maxLength;
}

int main()
{
    vector<int> candidates = {16, 17, 71, 62, 12, 24, 14};
    cout << "\nLength of combination that gives max bitwise AND is: " << largestCombination(candidates);

    return 0;
}