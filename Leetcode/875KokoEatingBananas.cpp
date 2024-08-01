#include <bits/stdc++.h>
using namespace std;

int timeReqdFnc(int k,vector<int> &piles){// find time reqd with this value of k:
    int time=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
        // traverse vector array:
        time+=(piles[i]+k-1)/k; //to get ceil we are using +k-1 or else do ceil

        // else do:     time += ceil(static_cast<double>(piles[i]) / k);
    }

    return time;
}

// BRUTE FORCE: TIME-O(max_element of array)*O(n)-->to cal time         -->time limit exceeded ERROR
int brute_force(vector<int> &piles, int h)
{
    int maxK=*max_element (piles.begin(), piles.end());
    // cout<<"I go till : "<<maxK<<endl;
    for(int k=1;k<=maxK;k++){
        // find time reqd with this value of k:
        int timeReqd=timeReqdFnc(k,piles);
        if(timeReqd<=h){
            return k;   //break instantly
        }
    }
    return -1;
}

// BINARY SEARCH: TIME-O(log(max_element of array))-->binary search *  O(n)-->to cal time
int minEatingSpeed(vector<int> &piles, int h)
{
    int low=1; //1banana/hour
    int high=*max_element(piles.begin(),piles.end());
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;

        int timeReqd=timeReqdFnc(mid,piles);

        if(timeReqd<=h){
            // can be possible
            ans=mid;
            // but check if MINIMum
            high=mid-1;
        }
        else if(timeReqd>h){
            // not possible
            low=mid+1;
        }

    }
    return ans;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    // op:4
    cout <<"\nBRUTE: Koko has to eat bananas at MINIMUM "<< brute_force(piles, h)<<" bananas/hour to finish in "<<h<<" hours";
    cout <<"\nKoko has to eat bananas at MINIMUM "<< minEatingSpeed(piles, h)<<" bananas/hour to finish in "<<h<<" hours";

    return 0;
}