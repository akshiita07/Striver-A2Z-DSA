class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int distance = 0;
        int n = moves.length();
        // count number of L's:
        int countL = count(moves.begin(), moves.end(), 'L');
        // count number of R's:
        int countR = count(moves.begin(), moves.end(), 'R');
        // count number of _'s:
        int countDash = count(moves.begin(), moves.end(), '_');
        // if count L>=R then replace _ with L
        if (countL >= countR) {
            countL += countDash;
        } else {
            // if count R>L then replace _ with R
            countR += countDash;
        }
        // for L -- and for R ++
        distance = countR - countL;
        return abs(distance);
    }
};
