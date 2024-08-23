#include <bits/stdc++.h>
using namespace std;

vector<int> findFactors(int num)
{
    vector<int> ans;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            ans.push_back(i);
            if ((num / i) != i)
            {
                ans.push_back((num/i));
            }
        }
    }
    return ans;
}
bool checkPrime(int num)
{
    int c = 0;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            c++;
            if ((num / i) != i)
            {
                c++;
            }
        }
    }
    if (c == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// TIME: O(sqrt(n) + n*sqrt(n))
// SPACE: O(n)->to give ans
void brute_force(int num)
{
    vector<int> ans;
    // find all factors
    vector<int> factors = findFactors(num);
    // check if factors r prime or not
    for (auto it : factors)
    {
        if (checkPrime(it) == true)
        {
            ans.push_back(it);
        }
    }
    cout << "\nThe prime factors of " << num << " are:";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// optimized:   school approach
// TIME: O(sqrt(n)->for loop * logn-->for divisions)
// SPACE: O(n)-for ans
void AllPrimeFactors(int num){
    vector<int> ans;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            ans.push_back(i);
            // keep on dividing number
            while(num%i==0){
                num=num/i;
            }
        }
    }
    // add remaining prime no
    if(num!=1){
        ans.push_back(num);
    }
    cout << "\nThe prime factors of " << num << " are:";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// using sieve of ersothenis
vector<int> primeNumbersTillN(int n) 
{ 
 	// Write your code here
     // create array:
    // lesser than n:so take of size n only
    vector<int> primeArr(n+1);
    // initialise from 2 to n as 1s
    for(int i=2;i<=n;i++){
        primeArr[i]=1;
    }

    //loop to find primes:  go only upto sqrt(n)
    for(int i=2;i<=sqrt(n);i++){
        // check if isprime
        if(primeArr[i]==1){
            // change all multiples to 0
            // start checking from i*i
            for(int j=i*i;j<=n;j=j+i){
                primeArr[j]=0;
            }
        }
    }

    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(primeArr[i]==1){
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    int n1 = 100;
    // brute_force(n1);
    AllPrimeFactors(n1);
    cout << endl;
    int n2 = 35;
    // brute_force(n2);
    AllPrimeFactors(n2);
    cout << endl;
    int n3 = 60;
    // brute_force(n3);
    AllPrimeFactors(n3);

    return 0;
}