#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        // to get max number starting wale 6 ko change to 9

        // convert number into an array of digits:
        vector<int> digits;
        while(num>0){
            digits.push_back(num%10);
            num=num/10;
        }
        //digits pushed in reverse order <---- this way
        // now find first occurring 6 in this array:
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            // start from msb to lsb
            if(digits[i]==6){
                digits[i]=9;
                break;
            }
        }
        // convert array back to n
        string numStr="";
        for(int i=n-1;i>=0;i--){
            numStr+=to_string(digits[i]);
        }
        //string to integer
        num=stoi(numStr);
        return num;
    }
};

int main()
{
    
    return 0;
}