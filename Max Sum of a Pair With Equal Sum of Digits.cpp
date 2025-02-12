class Solution {
public:

    int calculateSumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int,int>> mp;
        for (const auto& num: nums) {
            int sum = calculateSumOfDigits(num);
            if (mp.find(sum) == mp.end()) {
                mp[sum] = {num, -1};
            } else {
                auto& [max1, max2] = mp[sum];
                if (num > max1) {
                    max2 = max1;
                    max1 = num;
                } else if (num > max2) {
                    max2 = num;
                }
            }
        }
        int maxSum = -1;
        for (const auto& it: mp) {
            if (it.second.second != -1) {
                maxSum = max(maxSum, it.second.first + it.second.second);
            }
        }
        return maxSum;
    }
};
