class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // both strings of length 4
        // 2possibilities of indices: i=0,j=2, i=1,j=3
        if(s1==s2){
            return true;
        }
        string newS1=s1;
        swap(s1[0],s1[2]);
        if(s1==s2){
            return true;
        }
        swap(s1[1],s1[3]);
        if(s1==s2){
            return true;
        }
        // 2nd reverse try:
        swap(newS1[1],newS1[3]);
        if(newS1==s2){
            return true;
        }
        swap(newS1[0],s1[2]);
        if(newS1==s2){
            return true;
        }
        return false;
    }
};
