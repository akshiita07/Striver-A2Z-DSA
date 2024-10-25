#include <bits/stdc++.h>
using namespace std;

vector<string> removeSubfolders(vector<string> &folder)
{
    // Sort the folders lexicographically
    sort(folder.begin(), folder.end());
    vector<string> ans;

    // Iterate through each folder
    for (auto it:folder)
    {
        // 3 conditions:
        // 1. If ans array is empty, we add the current folder it to array because there is no previous folder to compare it against
        // 2. it.compare(0, ans.back().size(), ans.back()) checks if the current folder it starts with the last folder in ans array
        // 3. check if the character immediately following the last folder in result within f is a '/'
        if (ans.empty() || it.compare(0, ans.back().size(), ans.back()) != 0 || it[ans.back().size()] != '/')
        {
            ans.push_back(it);
        }
    }

    return ans;
}

int main()
{
    vector<string> folder={"/a","/a/b","/c/d","/c/d/e","/c/f"};
    cout<<"\nFolders after removing all sub-folders in those folders";
    vector<string> ans=removeSubfolders(folder);
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}