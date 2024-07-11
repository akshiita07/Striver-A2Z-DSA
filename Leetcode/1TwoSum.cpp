#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- TIME-O(n^2)     SPACE-O(n)
void twoSum_brute(int arr[],int n,int k){
    vector<int> ans;

    for(int i=0;i<n;i++){
        // start from next
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }

    // result print
    for(auto it:ans){
        cout<<it<<" ";
    }
}

// BETTER- HASHING- TIME-O(n*logn) 
// but if unordered_map then O(n*1) but in owrst case O(n^2) 
    // SPACE-O(n)
void twoSum_better(int arr[],int n,int k){
    vector<int> ans;

    // hash map that stores :elements,index
    map<int,int> hashArr;

    // i+_=k
    for(int i=0;i<n;i++){
        int fNo=arr[i];
        int sNo=k-fNo;            //9-2=7 reqd

        if(hashArr.find(sNo)!=hashArr.end()){
            // found element
            ans.push_back(i);
            ans.push_back(hashArr[sNo]);
        }else{
            hashArr[fNo]=i;
        }

    }

    // result print
    for(auto it:ans){
        cout<<it<<" ";
    }
}

// OPTIMAL -- WITHOUT USING MAP-->     2POINTER APPROACH             TIME-O(n*logn) 
// but if unordered_map then O(n*1) but in owrst case O(n^2) 
    // SPACE-O(n)
void twoSum_optimal(int arr[],int n,int k){
    vector<int> ans;

    // sort d array
    sort(arr,arr+n);
    int i=0;        //start
    int j=n-1;      //last
    while(i<j){     //i must not cross j
        int sum=arr[i]+arr[j];
        if(sum==k){
            ans.push_back(i);
            ans.push_back(j);
            break;
        }
        else if(sum>k){
            j--;
        }
        else if(sum<k){
            i++;
        }
    }

    // result print
    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main()
{
    int arr[]={2,7,11,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=9;
    // twoSum_brute(arr,n,k);
    // twoSum_better(arr,n,k);
    twoSum_optimal(arr,n,k);

    return 0;
}