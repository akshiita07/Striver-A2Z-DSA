#include <bits/stdc++.h>
using namespace std;

int maxProfit(int arr[],int n){
    // 1 transaction only
    int profit=0;
    int maxProfit=0;
    int buy=arr[0];
    // O(n)
    for(int i=1;i<n;i++){
        // profit=arr[i]-buy;
        // maxProfit=max(profit,maxProfit);
        // // buy- min
        // buy=min(buy,arr[i]);
        if(arr[i]>arr[i-1]){
            maxProfit+=arr[i]-arr[i-1];
        }
    }
    return maxProfit;
}

struct tweet{
    int userId;
    int tweetId;
    int followers;
    string content;
};
// getNewsFeed(userId)
// post(userId, tweetId)
class twitter{
    private:
        unordered_map<int,tweet> hashMap;       //stores tid,
    public:
        void post(int userId,int tweetId,string content){
            tweet newPost;
            newPost.content=content;
            newPost.userId=userId;
            newPost.tweetId=tweetId;
            hashMap[newPost.tweetId]
        }
};

int main()
{
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nMax profit is: "<<maxProfit(arr,n);
    return 0;
}