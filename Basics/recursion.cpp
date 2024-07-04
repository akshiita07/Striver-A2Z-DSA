#include <bits/stdc++.h>
using namespace std;
// SOLVE USING RECURSION: WHEN FNC CALLS ITSELF UNITL A SPECIFIC CONDITION IE BASE CONDITION IS MET

// Q1. Print name n times:
// TIME COMPLEXITY: O(n) ->fnc calls itself for n times
// SPACE COMPLEXITY: O(n)-> using stack space
void printName(int count, int n)
{
    if (count > n)      //base case
    {
        return;
    }
    cout << "Akshu" << endl;
    printName(count + 1, n);
}

// Q2. Print linearly from 1 to n
void printOnetoN(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    printOnetoN(i+1,n);
}

// Q3. Print linearly from n to 1
void printNtoOne(int n){
    if(n<1){
        return;
    }
    cout<<n<<" ";
    printNtoOne(n-1);
}

// Q4. Print linearly from 1 to n using BACKTRACKING
void backtrackingOnetoN(int n){
    if(n<1){
        return; 
    }
    backtrackingOnetoN(n-1);
    cout<<n<<" ";           //print call after recursion
}

// Q5. Print linearly from n to 1 using BACKTRACKING
void backtrackingNtoOne(int i,int n){
    if(i>n){
        return; 
    }
    backtrackingNtoOne(i+1,n);
    cout<<i<<" ";
}

// Q6. Sum of first n natural nos: PARAMETRISED METHOD
int sumFirstN_param(int sum,int n){
    if(n<1){
        return sum;
    }else{
        sumFirstN_param(sum+n,n-1);
    }
}

// Q6. Sum of first n natural nos: FUNCTION METHOD
int sumFirstN_fnc(int n){
    if(n<1){
        return 0;
    }else{
        return n+sumFirstN_fnc(n-1);
    }
}

// Q7.Factorial of n
int fact(int n){
    if(n<1){
        // 0!=1
        return 1;
    }
    return n*fact(n-1);
}

//  Q8. Reverse an array:
// void revArr(){
//     int arr[]={1,2,3,4,2};
//     vector<int> v;
//     for(int i=4;i>=0;i--){
//         v.emplace_back(arr[i]);
//     }

//     for(auto x:v){
//         cout<<x<<" ";
//     }
// }

int main()
{
    // int count = 1;
    // printName(count, 5);

    // printOnetoN(1,10);

    // printNtoOne(10);

    // backtrackingOnetoN(10);

    // backtrackingNtoOne(1,10);

    // cout<<"Sum of first 5 nat nos parametrised : "<<sumFirstN_param(0,5)<<endl;

    // cout<<"Sum of first 5 nat nos fnct : "<<sumFirstN_fnc(5)<<endl;

    // cout<<"Factorial of 4 is: "<<fact(4)<<endl;

    // revArr();

    return 0;
}