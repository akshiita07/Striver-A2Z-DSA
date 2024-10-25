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
        // If the result is empty or the current folder does not start with the last folder in result + "/"
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