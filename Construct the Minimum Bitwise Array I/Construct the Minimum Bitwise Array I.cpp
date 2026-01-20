// Solution for Construct the Minimum Bitwise Array I in CPP

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> answer;

        for (int idx = 0; idx < n; idx++) {

            int target = nums[idx];

            /*
                Special case:
                2 (binary: 10) cannot be formed because:
                - No x exists such that x OR (x + 1) = 2
            */
            if (target == 2) {
                answer.push_back(-1);
                continue;
            }

            bool foundValid = false;

            /*
                We iterate over bit positions to find
                the FIRST zero bit in target.

                WHY first zero bit?
                -------------------
                Clearing the lowest possible bit i.e. 1 just before 0
                gives the minimum possible value of x.
            */
            for (int bit = 1; bit < 32; bit++) {

                /*
                    If current bit is already set (1),
                    skipping it because flipping it won't help.
                */
                if (target & (1 << bit)) continue;

                /*
                    We flip the previous bit (bit - 1)
                    to simulate the "carry" behavior of x + 1.

                    XOR is used to flip exactly one bit.
                */
                int candidate = target ^ (1 << (bit - 1));

                answer.push_back(candidate);
                foundValid = true;
                break;
            }

            /*
                If no suitable bit position was found,
                then no valid x exists.
            */
            if (!foundValid) {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};
