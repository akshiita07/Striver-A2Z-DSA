class Solution {
public:
    /* brute force:
        int findPrefixLength(int num1, int num2) {
            // convert both numbers to string
            string strNum1 = to_string(num1);
            string strNum2 = to_string(num2);
            int commonPref = 0;

            for (int i = 0; i < min(strNum1.length(), strNum2.length()); i++) {
                if (strNum1[i] == strNum2[i]) {
                    commonPref++;
                } else {
                    // first uncommon found so stop
                    break;
                }
            }
            return commonPref;
        }

        int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
            int n1 = arr1.size();
            int n2 = arr2.size();
            int maxLen = 0;
            for (int i = 0; i < n1; i++) {
                for (int j = 0; j < n2; j++) {
                    // for pair of int i & j find max common prefix
                    int commonPrefix = findPrefixLength(arr1[i], arr2[j]);
                    maxLen = max(maxLen, commonPrefix);
                }
            }
            return maxLen;
        }
        */
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // Insert all prefixes of all numbers in nums1 into the set
        // A prefix here is obtained by repeatedly dividing the number by 10
        for (int num : arr1) {
            for (; num; num /= 10) {
                prefixes.insert(num);
            }
        }

        // Initialize 'longestPrefixLength' to store the length of the longest
        // prefix found
        int longestPrefixLength = 0;

        // Iterating through each number in nums2
        for (int num : arr2) {
            // Break down the number into prefixes and check against our set
            for (; num; num /= 10) {
                // If the current prefix is in the set, it's a common prefix
                if (prefixes.count(num)) {
                    // Logarithm base 10 of num gives us the number of digits -
                    // 1
                    longestPrefixLength =
                        max(longestPrefixLength, (int)log10(num) + 1);
                    // once the longest prefix for current num is found, no need
                    // to look for shorter ones
                    break;
                }
            }
        }
        // Return the length of the longest common prefix
        return longestPrefixLength;
    }
};
