// Solution for Find Unique Binary String in CPP

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        /*
            We construct a binary string that is guaranteed
            to differ from every string in nums.

            Idea: Cantor's Diagonal Argument
            --------------------------------

            For each string nums[i], we flip the i-th bit.

            This guarantees the new string differs from nums[i]
            at position i, meaning it cannot equal nums[i].

            Therefore, the constructed string cannot match
            any string in the array.
        */

        int n = nums.size();

        string differentString = "";

        for (int index = 0; index < n; index++) {

            /*
                Look at the diagonal bit nums[index][index]

                Flip it:
                0 → 1
                1 → 0
            */
            if (nums[index][index] == '0')
                differentString += '1';
            else
                differentString += '0';
        }

        return differentString;
    }
};
