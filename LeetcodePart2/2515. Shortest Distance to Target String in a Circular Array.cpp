class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int minDist = INT_MAX;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int steps = abs(i - startIndex);
                minDist = min(minDist, min(steps, n - steps));
            }
        }
        if (minDist == INT_MAX) {
            return -1;
        }
        return minDist;
    }
};
