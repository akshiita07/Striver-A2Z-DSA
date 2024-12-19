#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int> &arr)
{
    // split array into max no of chunks st on sorting each chunk and concatenating we get orig sorted array
    int n = arr.size();
    int maxValInChunk=0;
    int ans=0;
    for(int i=0;i<n;i++){
        maxValInChunk=max(maxValInChunk,arr[i]);
        if(maxValInChunk==i){
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 4};
    cout << "\nMax chunks possible are: " << maxChunksToSorted(arr);

    return 0;
}