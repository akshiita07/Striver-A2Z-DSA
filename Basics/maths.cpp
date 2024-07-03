#include <bits/stdc++.h>
using namespace std;

void extractDigits(int n)
{
    /*MY APPROACH-
    cout << "Digit is: " << n % 10 << endl; //      1234%10=1230 rem-4
        n = n / 10;                                      //      1234/10=123
        cout << "Next digit is: " << n % 10 << endl;     //      123%10=120 rem-3
        n = n / 10;                                      //      123/10=12
        cout << "Next digit is: " << n % 10 << endl;     //      12/10=10 rem-2
        n = n / 10;                                      //      12/10=1
        cout << "Next digit is: " << n << endl;          //      1
        */

    // first calculate no of digits in input no n
    while (n > 0)
    {
        cout << "Digit is: " << n % 10 << endl;
        n = n / 10;
    }
}

int countDigits(int N)
{
    int no = N;
    // an array to store digits
    vector<int> v;

    // ans store
    int count = 0;

    // digits extract of N
    while (no > 0)
    {
        // cout<<"Digit is: "<<N%10<<endl;
        v.push_back(no % 10);
        no = no / 10;
    }
    for (auto x : v)
    {
        cout << x << " ";
    }

    // remove any 0s if present in vector
    v.erase(remove(v.begin(), v.end(), 0), v.end());

    cout << "After removal of all 0s: \n";
    for (auto x : v)
    {
        cout << x << " ";
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (N % v[i] == 0)
        {
            count++;
        }
    }

    return count;
}

int reverseDigits(int x)
{
    int rNo = 0;
    while (x > 0)
    {
        cout << "Digit is: " << x % 10 << endl;
        rNo = (rNo) * 10 + (x % 10);
        cout << "reverse: " << rNo << endl;
        x = x / 10;
    }

    return rNo;
}

bool palindrome(int n)
{
    // Write your code here
    int rNo = reverseDigits(n);
    if (rNo == n)
    {
        return true;
    }
    return false;
}

// code for armstrong number begins here:
int noDigits(int num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num = num / 10;
    }
    return count;
}

vector<int> extractDigitsInVector(int num)
{
    vector<int> v;
    while (num > 0)
    {
        v.push_back(num % 10);
        num = num / 10;
        // v={3,2,1}
    }
    return v;
}

bool isArmstrong(int num)
{
    vector<int> v;
    // extract no of digits
    int powDigit = noDigits(num);
    cout << "\nThe no of digitsare= " << powDigit << endl;

    // extract all digits & sum them by
    // raising them to powDigit
    v = extractDigitsInVector(num);

    cout << "Extracting digits from vector: \n";
    for (auto x : v)
    {
        cout << x << " ";
    }

    int sum = 0;
    // sum & raise digits from this
    for (auto it = v.begin(); it != v.end(); it++)
    {
        int power = ceil(pow(*it, powDigit));
        cout << "\nPower of " << *it << " is: " << power << endl;
        sum = power + sum;
        cout << "\nsum for " << *it << " is: " << sum << endl;
    }
    cout << "\nThe sum of digits raised to no of digits= " << sum << endl;

    if (sum == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// print divisors starts here:

// {// NOT OPTIMAL CODE:
// // find factors of no
// vector<int> factors(int n)
// {
//     vector<int> v;
//     for (int i = 1; i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             // cout<<i<<" is a factor of "<<n<<endl;
//             v.push_back(i);
//         }
//     }
//     cout << "\nElements in factor vector are - ";
//     for (auto x : v)
//     {
//         cout << x << " ";
//     }
//     cout << endl;
//     return v;
// }

//   int divisors(int n)
// {
//     vector<int> v;
//     // extract digits into vector:
//     for (int i = 1; i <= n; i++)
//     {
//         v.push_back(i);
//     }
//     cout << "Elements in vector are";
//     for (auto x : v)
//     {
//         cout << x << " ";
//         // op: 1 2 3 4
//     }
//     // find divisors of each element of vector:
//     vector<int> fact;
//     vector<int> factAll;
//     for (auto it = v.begin(); it != v.end(); it++)
//     {
//         // *it divisors?
//         fact = factors(*it);
//         for (auto it = fact.begin(); it != fact.end(); it++)
//         {
//             // *add to all
//             factAll.push_back(*it);
//         }
//     }
//     // sum of all the factors in fact vector
//     int sum = 0;
//     for (auto it = factAll.begin(); it != factAll.end(); it++)
//     {
//         sum += *it;
//     }
//     return sum;
// }

// OPTIMAL METHOD TO FIND DIVISORS
vector<int> divOpt(int n)
{
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // cout << i << " ";
            v.push_back(i);
            if (i != (n / i))
            {

                // cout << (n / i) << " ";
                v.push_back(n / i);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << "Printing divisors of " << n << endl;
    for (auto x : v)
    {
        cout << x << " ";
    }

    return v;
}
long long optSumOfDivisors(int N)
{
    vector<int> fact;
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        // for 1,2,3,4=i
        sum += i * (N / i);
        cout << "i= " << i << endl;
        cout << "N/i= " << N / i << endl;
        cout << sum << endl;
    }

    // sum of all factors
    return sum;
}

bool isPrime(int num)
{
    vector<int> v;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            v.push_back(i);
            if (i != (num / i))
            {
                v.push_back(num / i);
            }
        }
    }

    cout << "Elements in vector r: \n";
    for (auto x : v)
    {
        cout << x << " ";
    }

    if (v.size() > 2)
    {
        return false;
    }
    return true;
}

// GREATEST COMMON DIVISOR- brute force approach
int gcd(int a, int b)
{
    int ans;

    for(int i=min(a,b);i>=1;i--){
        if(a%i==0 && b%i==0){
            ans=i;
            break;
        }
    }
    return ans;
}

// GREATEST COMMON DIVISOR- USING EUCLIDEAN ALGO
int gcdEuclideanAlgo(int a, int b)
{
    int ans;

    // a>b
    while(a!=0 && b!=0){        //jaise hi any one becomes 0 then remaining is gcd
        if(a>=b){
            // gcd(a,b)=gcd(a%b,b);
            a=a%b;

        }else{
            // gcd(a,b)=gcd(a,b%a);
            b=b%a;
        }
    }

    if(a==0){
        // b will be gcd
        ans=b;
    }else{
        // a is gcd
        ans=a;
    }
    
    return ans;
}

// LEAST COMMON FACTOR
int lcm(int a, int b)
{
    int ans = (a*b)/gcd(a,b);

    return ans;
}

int main()
{
    // extractDigits(7789);

    // cout << "Count is: " << countDigits(22074);

    // cout << "Reversing digits of 123 gives: " << reverseDigits(123);

    // cout << "Is 121 a palindrome: " << palindrome(121);
    // cout << "Is 321 a palindrome: " << palindrome(321);

    // cout << "Is 153 armstrong numb: " << isArmstrong(153);
    // cout << "Is 13 armstrong numb: " << isArmstrong(13);

    // cout << "Sum of divisors of n=4 are: " << divisors(4);
    // cout<<"Sum of divisors of n=5 are: "<<divisors(5);
    // factors(4);

    // cout << "Divisors of 36 are: ";
    // divOpt(36);

    // cout << "Sum of divisors of 4 optimized r: " << optSumOfDivisors(4);

    // cout << "Is 11 prime: " << isPrime(11) << endl;

    // cout<<"GCD of "<<a<<" & "<<b<<" is:"<<gcd(5,10);
    // cout << "GCD of 5,10 is:" << gcd(5, 10) << endl;
    // cout<<"GCD of 8,14 is:"<<gcd(14,8)<<endl;

    cout<<"GCD of 8,14 using euclidean algo is:"<<gcdEuclideanAlgo(14,8)<<endl;

    // cout << "LCM of 5,10 is:" << lcm(5, 10) << endl;
    // cout<<"LCM of 8,14 is:"<<lcm(14,8)<<endl;

    return 0;
}