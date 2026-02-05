// Solution for Transformed Array in CPP

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        int n = nums.size();

        // Result array to store transformed values
        vector<int> transformedResult(n);

        // Traverse each index independently
        for (int index = 0; index < n; index++) {

            /*
                nums[index] tells how many steps to move.
                We take modulo n to avoid unnecessary full rotations
                (since array is circular).
            */
            int steps = nums[index] % n;

            /*
                Calculate the new index after moving:
                - positive steps -> move right
                - negative steps -> move left
            */
            int targetIndex = (index + steps) % n;

            /*
                In C++, modulo of negative numbers can be negative.
                So we normalize the index to stay within [0, n-1].
            */
            if (targetIndex < 0) {
                targetIndex += n;
            }

            /*
                Assign the value present at the landed index
                to the current position in the result array.
            */
            transformedResult[index] = nums[targetIndex];
        }

        return transformedResult;
    }
};
