class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int less = 0, equal = 0;
        for (const auto& num: nums) {
            if (num < pivot) {
                less++;
            } else if (num == pivot) {
                equal++;
            }
        }
        int i = 0, j = less, k = less + equal;
        vector<int> res(n);
        for (const auto& num: nums) {
            if (num < pivot) {
                res[i++] = num;
            } else if (num == pivot) {
                res[j++] = num;
            } else {
                res[k++] = num;
            }
        }
        return res;
    }
};
