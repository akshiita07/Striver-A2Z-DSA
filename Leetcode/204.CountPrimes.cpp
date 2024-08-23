#include <bits/stdc++.h>
using namespace std;

int isPrime(int n){
    int c=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            c++;
            if((n/i)!=i){
                c++;
            }
        }
    }
    if(c==2){
        return 1;
    }else{
        return 0;
    }
}
// TIME: O(n->loop*sqrt(n)->check for prime)
// SPACE: O()
int brute_force(int n)
{
    int c=0;
    if(n==0 || n==1){
        // no prime factors exist before this no
        return 0;
    }
    for(int i=2;i<n;i++){
        if(isPrime(i)==1){
            c++;
        }
    }
    return c;
}

// optimized using prefix sum
int better(int n){
    if(n==0 || n==1){
        // no prime factors exist before this no
        return 0;
    }
    vector<int> isPrimeArray(n,0);
    for(int i=0;i<n;i++){
        isPrimeArray[i]=isPrime(i);
    }
    int count=0;
    for(int i=2;i<n;i++){
        count+=isPrimeArray[i];
        isPrimeArray[i]=count;
    }
    return isPrimeArray[n-1];
}


// using sieve of erathosthenes: O(N∗log(log(N))) MOST OPTIMAL APPROACH:
// TIME: O(N->loop to set 1s + Sqrt(N)(N∗log(log(N))) + O(n)->to count )
// SPACE: O(n)->for primeArr
int countPrimes(int n){
    // create array:
    // lesser than n:so take of size n only
    vector<int> primeArr(n);
    // initialise from 2 to n as 1s
    for(int i=2;i<n;i++){
        primeArr[i]=1;
    }

    //loop to find primes:  go only upto sqrt(n)
    for(int i=2;i<sqrt(n);i++){
        // check if isprime
        if(primeArr[i]==1){
            // change all multiples to 0
            // start checking from i*i
            for(int j=i*i;j<n;j=j+i){
                primeArr[j]=0;
            }
        }
    }

    int count=0;
    for(int i=2;i<n;i++){
        if(primeArr[i]==1){
            count++;
        }
    }
    return count;
}

int main()
{
    int n = 10;
    cout << "\nBRUTE FORCE-The no of prime factors that are lesser than " << n << " is: " << brute_force(n);
    cout << "\nBETTER: The no of prime factors that are lesser than " << n << " is: " << better(n);
    cout << "\nOPTIMAL: The no of prime factors that are lesser than " << n << " is: " << countPrimes(n);

    return 0;
}