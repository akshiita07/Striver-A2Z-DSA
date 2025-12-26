class Solution {
public:
    int bestClosingTime(string customers) {
        // customers consist only of characters N and Y
        // Y: customer comes at ith hour
        // N: no customer at ith hour
        // penalty += ( shop open but no customers-> penalty +1 ),( shop closed
        // N customers come-> penalty+1 ) return earliest hour at which shop
        // must be closed for MIN penalty
        int n = customers.size();
        // penalty if shop closes at hour 0
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y') {
                penalty++;
            }
        }

        int minPenalty = penalty;
        int bestHour = 0;

        for (int j = 1; j <= n; j++) {
            if (customers[j - 1] == 'Y') {
                penalty--;
            } else {
                penalty++; // open but no customer
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }
        return bestHour;
    }
};
