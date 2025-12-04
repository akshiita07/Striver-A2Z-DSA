class Solution {
public:
    int countCollisions(string directions) {
        // n cars: 0 to n-1
        int n=directions.length();
        //l: left r:right s:staying at current point
        // 2 cars moving in opp dirn -> collide -> +=2
        // moving car collision with stationary car   -> collide -> +=1
        // after collision-> cars CANNOT move
        // return total number of collisions
        int noOfCollisions=0;
        int flag=-1;
        // flag=-1: no right moving cars found yet by left for collision
        // flag=0: stationary car
        // flag>1: right moving car
        for(auto it:directions){
            if(it=='L'){
                //left:
                if(flag>=0){
                    noOfCollisions+=flag+1;
                    flag=0;
                }
            }else if(it=='R'){
                //right:
                if(flag>=0){
                    flag++;
                }else{
                    flag=1;
                }
            }else if(it=='S'){
                //stationary:
                if(flag>0){
                    noOfCollisions+=flag;
                }
                flag=0;
            }
        }
        return noOfCollisions;
    }
};
