#include <bits/stdc++.h>
using namespace std;

int sumOfNextK(vector<int> &code, int index, int k)
{
    // index ke baad wale k numbers ka sum
    int sum = 0;
    int n = code.size();
    for (int i = 1; i <= k; i++)
    {
        sum += code[(index + i) % n];
    }
    return sum;
}

int sumOfPreviousK(vector<int> &code, int index, int k)
{
    // index ke prev wale k numbers ka sum
    int sum = 0;
    int n = code.size();
    // k is less than 0 so go abs(k) times
    for (int i = 1; i <= abs(k); i++)
    {
        sum += code[(index - i + n) % n];
    }
    return sum;
}

vector<int> decrypt(vector<int> &code, int k)
{
    int n = code.size();
    // If k > 0, replace the ith number with the sum of the next k numbers.
    // If k < 0, replace the ith number with the sum of the previous k numbers.
    // If k == 0, replace the ith number with 0.
    // code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1]
    //  return the decrypted code to defuse the bomb
    vector<int> decryptedCode(n);
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            // for all n elements of code replace by 0"
            decryptedCode[i] = 0;
        }
    }
    else if (k > 0)
    {
        // sum of the next k numbers
        for (int i = 0; i < n; i++)
        {
            decryptedCode[i] = sumOfNextK(code, i, k);
        }
    }
    else if (k < 0)
    {
        // sum of the previous k numbers
        for (int i = 0; i < n; i++)
        {
            decryptedCode[i] = sumOfPreviousK(code, i, k);
        }
    }
    return decryptedCode;
}

int main()
{
    vector<int> code = {5, 7, 1, 4};
    int k = 3;
    // Output: [12,10,16,13]
    vector<int> ans = decrypt(code, k);
    cout << "The decrypted code is:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}