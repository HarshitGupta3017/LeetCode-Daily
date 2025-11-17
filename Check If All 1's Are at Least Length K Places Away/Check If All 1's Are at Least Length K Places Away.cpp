// Solution for Check If All 1's Are at Least Length K Places Away in CPP

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;
        for (int curr = 0; curr < nums.size(); curr++) {
            if (nums[curr] == 0) continue;
            if (prev != -1 && curr - prev - 1 < k) {
                return false;
            }
            prev = curr;
        }
        return true;
    }
};
