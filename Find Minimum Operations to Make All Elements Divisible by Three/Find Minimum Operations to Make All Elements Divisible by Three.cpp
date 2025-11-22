// Solution for Find Minimum Operations to Make All Elements Divisible by Three in CPP

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(), [](int num) {return num % 3 != 0;});
    }
};
