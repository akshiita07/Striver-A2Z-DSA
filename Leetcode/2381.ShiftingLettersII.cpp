#include <bits/stdc++.h>
using namespace std;

string brute_force(string s, vector<vector<int>> &shifts)
{
    //  shifts[i] = [starti, endi, directioni]
    // for each i in shifts:  shift the characters in s from the index starti to endi forward if directioni = 1, OR shift the characters backward if directioni = 0
    int len = s.length();
    string shiftedString = s;
    for (int i = 0; i < shifts.size(); i++)
    {
        int start = shifts[i][0];
        int end = shifts[i][1];
        int direction = shifts[i][2];

        for (int j = start; j <= end; j++)
        {
            char ch = shiftedString[j];
            int ascii = ch;
            if (direction == 0)
            {
                // backward:
                if (ascii == 97) // ie a
                {
                    shiftedString[j] = 'z';
                }
                else
                {
                    shiftedString[j] = ch - 1;
                }
            }
            else if (direction == 1)
            {
                // forward:
                if (ascii == 122) // ie z
                {
                    shiftedString[j] = 'a';
                }
                else
                {
                    shiftedString[j] = ch + 1;
                }
            }
        }
    }
    return shiftedString;
}

string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    //  shifts[i] = [starti, endi, directioni]
    // for each i in shifts:  shift the characters in s from the index starti to endi forward if directioni = 1, OR shift the characters backward if directioni = 0
    int len = s.length();
    vector<int> prefixSum(len + 1, 0);
    string shiftedString = s;

    for (int i = 0; i < shifts.size(); i++)
    {
        int start = shifts[i][0];
        int end = shifts[i][1];
        int direction = shifts[i][2];
        int val;

        if (direction == 0)
        {
            // backward:
            val = -1;
        }
        else if (direction == 1)
        {
            // forward:
            val = 1;
        }
        prefixSum[start]+=val;
        prefixSum[end+1]-=val;
    }
    int shiftAmt=0;
    for(int i=0;i<len;i++){
        shiftAmt+=prefixSum[i];
        int normalizeShiftAmt=shiftAmt%26;
        if(normalizeShiftAmt<0){
            normalizeShiftAmt+=26;
        }
        s[i]='a'+(s[i]-'a'+normalizeShiftAmt)%26;   //s[i]-'a'+normalizeShiftAmt to bring it to a integer format
    }

    return s;
}

int main()
{
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    cout << "\nString after shifting is: " << brute_force(s, shifts);
    cout << "\nString after shifting is: " << shiftingLetters(s, shifts);
    return 0;
}