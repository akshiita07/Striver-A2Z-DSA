#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mapElementWithFreq(string s)
{
    // return a map with element->frequency
    vector<pair<int, int>> hashMap;
    int n = s.length();
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            hashMap.push_back({s[i - 1] - '0', cnt});
            cnt = 1;
        }
    }
    return hashMap;
}

string createStringFromMap(vector<pair<int, int>> hashMap)
{
    string s = "";
    for (auto it : hashMap)
    {
        s += to_string(it.second) + to_string(it.first);
    }
    return s;
}

string countAndSay(int n)
{
    string ans = "1";
    // countAndSay(n) is the run-length encoding of countAndSay(n - 1)
    // RLE: (count of identical elements)(identical element)
    // return countAndSay(n)
    for (int i = 1; i < n; i++)
    {

        vector<pair<int, int>> hashMap = mapElementWithFreq(ans);
        ans = createStringFromMap(hashMap);
    }
    return ans;
}

int main()
{
    int n = 4;
    cout << "\ncountAndSay(" << n << ") = " << countAndSay(n);

    return 0;
}