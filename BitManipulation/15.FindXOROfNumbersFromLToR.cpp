#include <bits/stdc++.h>
using namespace std;

int bruteforce(int l, int r)
{
    int ans=0;
    for(int i=l;i<=r;i++){
        ans^=i;
    }
    return ans;
}

int findXORUptoN(int n)
{
    if(n%4==1){
        return 1;
    }
    else if(n%4==2){
        return n+1;
    }
    else if(n%4==3){
        return 0;
    }else{
        return n;
    }
}

int findXOR(int l, int r)
{
    return findXORUptoN(r)^findXORUptoN(l-1);
}

int main()
{
    int l = 4;
    int r = 8;
    cout << "\nBRUTE FORCE-->The XOR in range " << l << " to " << r << " is= " << bruteforce(l, r);
    cout << "\nThe XOR in range " << l << " to " << r << " is= " << findXOR(l, r);

    return 0;
}