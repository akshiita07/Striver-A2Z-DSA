class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // buy 2 candies-> 3rd free
        // cost of free candy<=min(cost candies bought)
        int n = cost.size();
        // return-> min cost of buying all candies
        //  sort in inc order:
        sort(cost.begin(), cost.end());
        int totalCost = 0;
        // buy last 2 and 3rd last get for free:
        int i = n - 1;
        while (i >= 0) {
            totalCost += cost[i];
            if (i - 1 >= 0) {
                totalCost += cost[i - 1];
            }
            // i-2 we get for free so skip:
            i-=3;
        }
        return totalCost;
    }
};
