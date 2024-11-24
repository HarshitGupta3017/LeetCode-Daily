class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // basic ques just count total negatives
        // if total negatives are even then they can be made positive using operation and we can 
        // return total sum
        // if odd total negatives then we need to reduce the smallest number from matrix as we can shift
        // negative sign to it using given operation
        int n = matrix.size();
        int count_negative = 0;
        long long sum = 0;
        int minAbs = INT_MAX;
        for (const auto& row: matrix) {
            for (int num: row) {
                sum += abs(num);
                minAbs = min(minAbs, abs(num));
                if (num < 0) count_negative++;
            }
        }
        return (count_negative % 2 == 0) ? sum : sum - 2 * minAbs;
    }
};
