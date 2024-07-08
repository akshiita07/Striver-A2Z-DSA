#include <bits/stdc++.h>
using namespace std;

int isSorted(int arr[],int n) {
  bool sorted = false;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i]<=arr[i + 1]) {
      sorted = true;
    }else{
        sorted=false;
        break;
    }
  }
  if (sorted) {
    return 1;
  } else {
    return 0;
  }
//   TIME- O(n)
}


int main()
{
    // int arr[]={1,2,3,4,5};
    // int arr[]={5,4,1,3,2};
    // int arr[]={0,0,0,1};
    int arr[]={4,5,4,4,4};

    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"The array is: "<<isSorted(arr,n);


    return 0;
}