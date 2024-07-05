#include <bits/stdc++.h>
using namespace std;

// Find how many times does a given number appear in an array
int noOfTimesRepeat(int arr[], int num, int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == num)
        {
            count++;
        }
    }
    return count;
    // this approach takes- O(n) time
}

// Find how many times does a given CHARACTER appear in an array

int noOfTimesCharRepeat(string s, char ch, int strLength)
{
    int count = 0;
    for (int i = 0; i < strLength; i++)
    {
        if (s[i] == ch)
        {
            count++;
        }
    }
    return count;
    // this approach takes- O(n) time
}

// to get in O(1) time: Hashing

int main()
{
    int arr[] = {1, 3, 2, 1, 3};
    int num = 1;
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    // cout<<"The number of times number "<<num<<" appears in array is= "<<noOfTimesRepeat(arr,num,arrLength)<<endl;

    int hash[10] = {0}; // maxm size till 10 ie initialised with 0
    // fill array with count
    for (int i = 0; i < arrLength; i++)
    {
        // precompute
        hash[arr[i]] += 1;
    }
    // fetch
    cout << "The number of times number " << num << " appears in HASH array is= " << hash[num] << endl;

    // CHARACTER HASHING:
    string s = "abcdabefc";
    char ch = 'c';

    // cout << "The number of times character " << ch << " appears in charHash array is= " << noOfTimesCharRepeat(s,ch,s.length()) << endl;

    int charHash[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        // precompute
        charHash[s[i] - 'a'] += 1;
    }
    // fetch
    // cout << "The number of times character " << ch << " appears in charHash array is= " << charHash[ch - 'a'] << endl;

    // FOR ALL CHARACTERS:
    int hashCharArray[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        // precompute
        hashCharArray[s[i]] += 1;
        // a-97 A-65 go to ascii value
    }
    // fetch
    // cout << "The number of times character " << ch << " appears in 256 characters array is= " << hashCharArray[ch] << endl;

    // HASHING USING MAP
    int arrMap[] = {1, 2, 3, 1, 3, 2, 12};
    int mapNo=2;
    int arrMapLength = sizeof(arrMap) / sizeof(arrMap[0]);

    unordered_map<int,int> mapHash;

    for (int i = 0; i < arrMapLength; i++)
    {
        // precompute
        mapHash[arrMap[i]] += 1;
    }
    
    cout<<"Elements in map : \n";
    for(auto it:mapHash){
        cout<<it.first<<":"<<it.second<<" ";
        // op-1:2 2:2 3:2 12:1 in map- O(logN)
        // op-3:2 12:1 2:2 1:2 in unordered map- O(1)
    }

    // fetch
    cout << "The number of times no " << mapNo << " appears in MAP is= " << mapHash[mapNo] << endl;

    // MAP HASHING FOR CHARACTERS:
    map<char,int> mapCharHash;
    //char:f requency
    for (int i = 0; i < s.length(); i++)
    {
        // precompute
        mapCharHash[s[i]] += 1;
    }
    
    cout<<"Elements in map : \n";
    for(auto it:mapCharHash){
        cout<<it.first<<":"<<it.second<<" ";
        // op-a:2 b:2 c:2 d:1 e:1 f:1
    }

    // fetch
    cout << "The number of times char " << ch << " appears in MAP is= " << mapCharHash[ch] << endl;

    // HASHING USING UNORDERED MAP

    return 0;
}