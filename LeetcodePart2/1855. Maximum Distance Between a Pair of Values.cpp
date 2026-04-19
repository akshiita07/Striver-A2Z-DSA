class Solution {
public:
    int maxDistanceBRUTE_FORCE(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int dist = INT_MIN;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (i <= j && nums1[i] <= nums2[j]) {
                    dist = max(dist, (j - i));
                }
            }
        }
        if (dist == INT_MIN) {
            return 0;
        }
        return dist;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        int dist = INT_MIN;
        while (i < n1 && j < n2) {
            // i<=j:
            j=max(i,j);
            if (nums1[i] <= nums2[j]) {
                dist = max(dist, (j - i));
                j++;
            } else {
                i++;
            };
        }
        if (dist == INT_MIN) {
            return 0;
        }
        return dist;
    }
};
