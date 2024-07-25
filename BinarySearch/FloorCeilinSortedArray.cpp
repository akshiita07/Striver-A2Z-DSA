#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr, int x)
{
    // largest element that is <=x
    int n = arr.size();
    int floor=-1;

    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            floor=arr[mid];
            break;
        }
        else if(arr[mid]>x){
            high=mid-1;
        }
        else if(arr[mid]<x){
            floor=arr[mid];
            low=mid+1;
        }
    }
    return floor;
}
int findCeil(vector<int> &arr, int x)
{
    // smallest element that is >=x
    int n = arr.size();
    int ceil;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            ceil=arr[mid];
            break;
        }
        else if(arr[mid]>x){
            ceil=arr[mid];
            high=mid-1;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
    }
    return ceil;
}
pair<int, int> getFloorAndCeil(vector<int> &arr, int x)
{
    int n = arr.size();
    pair<int, int> ans; //1st-floor 2nd-ceil
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            ans.first=arr[mid];
            ans.second=arr[mid];
            break;
        }
        else if(arr[mid]>x){
            ans.second=arr[mid];
            high=mid-1;
        }
        else if(arr[mid]<x){
            ans.first=arr[mid];
            low=mid+1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 4, 7, 8, 8, 10};
    int x = 5;
    cout << "\nThe floor of " << x << " is: " << findFloor(arr, x);     //4
    cout << "\nThe ciel of " << x << " is: " << findCeil(arr, x);       //7
    cout << "\nThe floor and ceil of " << x << " is: " << getFloorAndCeil(arr, x).first << " and " << getFloorAndCeil(arr, x).second << " respectively";

    return 0;
}