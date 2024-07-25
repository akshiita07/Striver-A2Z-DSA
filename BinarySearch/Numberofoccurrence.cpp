#include <bits/stdc++.h>
using namespace std;

int countOcc(vector<int> &arr, int x)
{
    int n=arr.size();
    int count=0;
    int low=0;
    int first=-1;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            // 1st occ
            first=mid;
            high=mid-1;
        }else if(arr[mid]>x){
            high=mid-1;
            
        }else{
            low=mid+1;
        }
    }
    if(first==-1){
        count=0;
    }
    low=0;
    int last=-1;
    high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            // 1st occ
            last=mid;
            low=mid+1;
        }else if(arr[mid]>x){
            high=mid-1;
            
        }else{
            low=mid+1;
        }
    }
    count=last-first+1;
    cout<<"\nThe no of times "<<x<<" occurrs in array is: "<<count;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3};
    int x = 3;
    countOcc(arr,x);

    return 0;
}