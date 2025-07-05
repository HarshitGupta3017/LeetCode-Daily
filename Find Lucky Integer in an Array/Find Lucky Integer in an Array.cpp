// Solution for Find Lucky Integer in an Array in CPP

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Encode frequency in the upper 16 bits of each number
        for (const int& num : arr) {
            int value = num & 65535; // Mask to get original number (lower 16 bits only)
            if (value <= n) {
                arr[value - 1] += (1 << 16); // Add frequency info using higher bits
            }
        }

        // Step 2: Check from largest to smallest for a lucky integer
        for (int val = n; val >= 1; val--) {
            int freq = arr[val - 1] >> 16; // Get frequency from upper 16 bits
            if (freq == val) {
                return val; // Return largest lucky integer
            }
        }

        // Step 3: No lucky integer found
        return -1;
    }
};
