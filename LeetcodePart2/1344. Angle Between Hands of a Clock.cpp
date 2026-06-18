class Solution {
public:
    double angleClock(int hour, int minutes) {
        // min hand: 360/60min= 6deg per min
        // hr hand: 360/12hr= 30deg per hr
        // 1hr=60mins hr hand moves 30deg so in 1 min hr hand moves 30/60=0.5deg
        //diff= hr-min hand
        double hourHand=(hour%12)*30+(minutes)*0.5;
        double minHand=(minutes%60)*6;
        double diff=abs(hourHand-minHand);
        //choose min angle
        return min(diff,360-diff);
    }
};
