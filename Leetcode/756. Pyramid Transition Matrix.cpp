class Solution {
public:
    map<string,vector<string>> mp;
    map<string,bool> dp;
    bool solve(int ind, string newlayer, string oldlayer, int n)
    {
        if(n==1) return true;
        
        if(ind==n-1)
        {
            if (dp.count(newlayer)) return dp[newlayer];
            return dp[newlayer]=solve(0,"",newlayer,n-1);
        }

        //for ind,ind+1 -> Check in mp what all possibilties are present
        string tmp = oldlayer.substr(ind,2);

        if(!mp.count(tmp)) return false; //not found a valid allowed

        for(auto x:mp[tmp]){
            if(solve(ind+1,newlayer+x,oldlayer,n)) //if any ans gives us true, we can break from loop and return true
                return true;
        }
        return false; //true not received above so return false
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        int n = bottom.size();


        for(auto x:allowed){
            mp[x.substr(0,2)].push_back(x.substr(2));
        }

        return solve(0,"",bottom,n);
    }
};
