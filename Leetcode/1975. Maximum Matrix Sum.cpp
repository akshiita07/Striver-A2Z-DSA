class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // choose any two adjacent elements of matrix and multiply each of them by -1. maximize the summation of the matrix's elements.
        long long noOfNegElems = 0;
        long long maxAbsSum = 0;
        int minAbsElem = INT_MAX;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxAbsSum += (long long)abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    noOfNegElems++;
                }
                minAbsElem = min(minAbsElem, abs(matrix[i][j]));
            }
        }
        // if total no of neg elems are odd then reduce sum:
        if (noOfNegElems % 2 != 0) {
            // reduce sum:
            maxAbsSum = maxAbsSum - 2 * minAbsElem;
        }
        return maxAbsSum;
    }
};
