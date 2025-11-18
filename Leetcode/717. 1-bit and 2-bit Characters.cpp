class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int i=0;
        //loop:
        while(i<n-1){
            if(bits[i]==1){
                //skip 2 places for a 2 bit character:
                i+=2;
            }else{
                //increment only once
                i+=1;
            }
        }
        // if i lands on last index then yes:
        if(i==n-1){
            return true;
        }
        return false;
    }
};
