#include <bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num)
{
    // 3 digit
    // only 1 unique number
    // return largest
    string ans="";
    int n=num.length();
    for(int i=0;i<n-2;i++){
        if(num[i]==num[i+1] && num[i+1]==num[i+2]){
            string temp=num.substr(i,3);
            if(temp>ans){
                ans=temp;
            }
        }
    }
    return ans;
}

int main()
{
    string num = "6777133339";
    cout << "\nAns: " << largestGoodInteger(num);

    return 0;
}