#include <bits/stdc++.h>
using namespace std;

int maxScore(string s)
{
    // no of zeroes in left + no of ones in right substring
    int n=s.length();
    int totalOnes=0;
    for(auto it:s){
        if(it=='1'){
            totalOnes++;
        }
    }
    int ans=0;
    int leftZeros=0;
    int rightOnes=totalOnes;
    for(int i=0;i<n-1;i++){
        if(s[i]=='0'){
            leftZeros++;
        }else{
            rightOnes--;
        }
        int currentScore=leftZeros+rightOnes;
        ans=max(ans,currentScore);
    }
    return ans;
}

int main()
{
    string s = "011101";
    cout << "\nMax score is: " << maxScore(s);

    return 0;
}