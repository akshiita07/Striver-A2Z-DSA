class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // n rows
        // 10 clm 
        // 4 person group together
        // 1 row: max 2 four-group
        unordered_map<int,unordered_set<int>> reservedRow;
        for(auto &it:reservedSeats){
            reservedRow[it[0]].insert(it[1]);
        }
        // lets assume each row can fit max 2 groups so ans:
        int maxi=2*n;

        //check for each reserved row:
        for(auto &[row,seat]:reservedRow){
            bool left=true;
            bool middle=true;
            bool right=true;
            for(int i=2;i<=5;i++){
                if(seat.count(i)){
                    //is reserved:
                    left=false;
                    break;
                }
            }
            for(int i=4;i<=7;i++){
                if(seat.count(i)){
                    //is reserved:
                    middle=false;
                    break;
                }
            }
            for(int i=6;i<=9;i++){
                if(seat.count(i)){
                    //is reserved:
                    right=false;
                    break;
                }
            }
            maxi-=2;
            if(left && right){
                maxi+=2;
            }else if(left || middle || right){
                maxi+=1;
            }
        }
        return maxi;
    }
};
