class Solution {
public:
    int findReverse(int n){
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int rev=stoi(s);
        cout<<"Reverse number is: "<<rev<<endl;
        return rev;
    }
    int mirrorDistance(int n) {
        int revNumber=findReverse(n);
        return abs(n-revNumber);
    }
};
