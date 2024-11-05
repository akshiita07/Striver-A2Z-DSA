#include <bits/stdc++.h>
using namespace std;

int minChanges(string s)
{
    // binary string s with even length
    // beautiful string conditions..partition string into substrings: 1. Each substring has an even length.
    // 2. Each substring contains only 1's or only 0's.
    // Return the minimum number of changes required to make the string s beautiful
    int n=s.length();
    int changes=0;
    for(int i=0;i<n;i=i+2){
        if(s[i]!=s[i+1]){
            changes++;
        }
    }
    return changes;
}

int main()
{
    string s = "1001";
    cout << "\nMin no of changes reqd to make string beautiful are: " << minChanges(s);
    return 0;
}