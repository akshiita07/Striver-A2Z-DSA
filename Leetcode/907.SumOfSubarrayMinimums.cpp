#include <bits/stdc++.h>
using namespace std;

// TIME: O(n^2)
// SPACE: O(1)
int bruteforce(vector<int> &arr)
{
    int mod = (int)(1e9 + 7); // 10^9+7
    int n = arr.size();
    int sum = 0;
    // find all subarrays
    for (int i = 0; i < n; i++)
    {
        int minElem = arr[i];
        for (int j = i; j < n; j++)
        {
            minElem = min(minElem, arr[j]);
            sum += minElem;
        }
    }
    // find min of all subarrays
    // find sum of mins of subarrays
    return sum % mod;
}

// TIME: O()
// SPACE: O()
vector<int> next_smaller_index(vector<int> &arr)
{
    // store INDEX in stack (not elements)
    stack<int> st;
    int n=arr.size();
    vector<int> nse(n);
    // start from back
    for(int i=n-1;i>=0;i--){
        while(st.empty()==false && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i]=n;
        }else{
            nse[i]=st.top();
        }
        st.push(i);
    }
    return nse;
}
// find previous smaller OR equal!! 
vector<int> previous_smaller_index(vector<int> &arr)
{
    // store INDEX in stack (not elements)
    stack<int> st;
    int n=arr.size();
    vector<int> pse(n);
    // start from front
    for(int i=0;i<n;i++){
        while(st.empty()==false && arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()){
            pse[i]=-1;
        }else{
            pse[i]=st.top();
        }
        st.push(i);
    }
    return pse;
}

// TIME: O(n)->for loop+O(2n+2n)->nsi&psi == O(5n)
// SPACE: O(2n)->2stacks used + O(2n)->vectors used to return psi & nsi == O(4n)
int sumSubarrayMins(vector<int> &arr)
{
    // where is next smaller index
    // where is previous smaller index
    // a=ur present index - NSI
    // b=ur present index - PSI
    // multiply a and b
    // multiply arr[ur present index] with it
    int sum = 0;
    vector<int> nsi = next_smaller_index(arr);  //TIME: O(2n)   SPACE:O(n)->stack
    vector<int> psi = previous_smaller_index(arr);  //TIME: O(2n)   SPACE:O(n)->stack
    int mod = (int)(1e9 + 7);
    for (int i = 0; i < arr.size(); i++)
    {
        // no of elemen on left
        int noElemOnLeft = i - psi[i];
        // no of elemen on right
        int noElemOnRight = nsi[i] - i;
        sum = sum + (noElemOnLeft * noElemOnRight * arr[i]);
        sum = sum % mod;
    }
    return sum;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << "\nBRUTE FORCE-> The sum of MINIMUM of all possible subarrays of arr is: " << bruteforce(arr);
    cout << "\nThe sum of MINIMUM of all possible subarrays of arr is: " << sumSubarrayMins(arr);

    return 0;
}