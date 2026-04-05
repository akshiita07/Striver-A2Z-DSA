class Solution {
public:
    bool judgeCircle(string moves) {
        // to reach at origin again there must be equal no of L & R  OR equal no of L & D
        int countL=0;
        int countR=0;
        int countU=0;
        int countD=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L'){
                countL++;
            }else if(moves[i]=='R'){
                countR++;
            }else if(moves[i]=='U'){
                countU++;
            }else if(moves[i]=='D'){
                countD++;
            }
        }
        if(countL==countR && countU==countD){
            return true;
        }
        return false;
    }
};
