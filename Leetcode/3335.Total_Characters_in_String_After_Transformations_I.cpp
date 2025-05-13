#include <bits/stdc++.h>
using namespace std;

// time: O(n² × t)
const int mod = 1e9 + 7;
int brute_Force(string s, int t)
{
    //  If the character is 'z', replace it with the string "ab" Otherwise, replace it with the next character in the alphabet.
    // Return the length of the resulting string after exactly t transformations
    string ans = s;
    // for each transformation:
    while (t > 0)
    {
        int n = ans.length();
        for (int i = 0; i < n; i++)
        {
            // apply transformation to each character:
            if (ans[i] == 'z')
            {
                ans[i] = 'a';
                ans.insert(i + 1, "b");
                i++; // as extra character is added & skip transformation on it
            }
            else
            {
                // increment the character by 1
                ans[i] = ans[i] + 1;
            }
            // update length:
            n = ans.length();
        }
        t--;
    }
    cout << "\nUpdated string becomes: " << ans;
    return ans.length() % mod;
}

// time: O(n × t)
int better_approach(string s, int t)
{
    //  If the character is 'z', replace it with the string "ab" Otherwise, replace it with the next character in the alphabet.
    // Return the length of the resulting string after exactly t transformations
    vector<char> charString(s.begin(), s.end());
    // for each transformation:
    while (t > 0)
    {
        vector<char> newString;
        for (int i = 0; i < charString.size(); i++)
        {
            char ch = charString[i];
            // apply transformation to each character:
            if (ch == 'z')
            {
                newString.push_back('a'); // 'a'
                newString.push_back('b'); // 'b'
            }
            else
            {
                // increment the character by 1
                newString.push_back(ch + 1);
            }
        }
        // update length:
        charString = move(newString);
        t--;
    }

    cout << "\nUpdated string becomes: ";
    for (auto it : charString)
    {
        cout << it;
    }
    return charString.size() % mod;
}

// time: O(26 × t)
int lengthAfterTransformations(string s, int t)
{
    //  If the character is 'z', replace it with the string "ab" Otherwise, replace it with the next character in the alphabet.
    // Return the length of the resulting string after exactly t transformations
    int n = s.length();
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++)
    {
        // count freq of each character:
        freq[s[i] - 'a']++;
    }
    // for each transformation:
    while (t > 0)
    {
        vector<int> newFreq(26, 0);
        for (int i = 0; i < 26; i++)
        {
            if (i == 25)
            {
                // character z:
                newFreq[0] = (newFreq[0] + freq[i]) % mod; // 'a'
                newFreq[1] = (newFreq[1] + freq[i]) % mod; // 'b'
            }
            else
            {
                newFreq[i + 1] = (newFreq[i + 1] + freq[i]) % mod; // 'next char'
            }
        }
        freq = newFreq;
        t--;
    }

    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        count = (count + freq[i]) % mod;
    }
    return count;
}

int main()
{
    string s = "abcyy";
    int t = 2;
    // op:"cdeabab" 7
    cout << "\nbrute_Force length of the resulting string after exactly " << t << " transformations= " << brute_Force(s, t);
    cout << "\nbetter_approach length of the resulting string after exactly " << t << " transformations= " << better_approach(s, t);
    cout << "\nlength of the resulting string after exactly " << t << " transformations= " << lengthAfterTransformations(s, t);

    return 0;
}