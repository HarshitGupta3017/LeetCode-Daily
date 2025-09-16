// Solution for Replace Non-Coprime Numbers in Array in CPP

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> finalArray;  // Stores the resulting modified array

        // Step 1: Traverse each number in the input array
        for (int num : nums) {
            // Step 2: Merge with the last number in finalArray while they are non-coprime
            while (!finalArray.empty()) {
                int lastNum = finalArray.back();  // Get the last number in result
                int currentNum = num;             // Current number being processed
                int currentGCD = gcd(lastNum, currentNum);

                if (currentGCD == 1) {
                    // If coprime, stop merging
                    break;
                }

                // Remove the last number and replace both with their LCM
                finalArray.pop_back();
                long long lcmValue = 1LL * lastNum / currentGCD * currentNum;
                num = (int)lcmValue;  // Update current number to merged LCM
            }

            // Step 3: Push the merged number (or original if no merge) into result
            finalArray.push_back(num);
        }

        return finalArray;
    }
};
