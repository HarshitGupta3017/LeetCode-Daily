// Solution for The Two Sneaky Numbers of Digitville in CPP

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        // 'originalSize' represents the expected size of the list (before two numbers repeated)
        int originalSize = nums.size() - 2;
        
        // 'xorAllElements' will hold the XOR of all elements in 'nums'
        int xorAllElements = 0;
        for (const int& val : nums) {
            xorAllElements ^= val;
        }
        
        // Now XOR all numbers from 0 to originalSize - 1.
        // This cancels out numbers that appeared exactly once,
        // leaving us with the XOR of only the two sneaky (duplicate) numbers.
        for (int num = 0; num < originalSize; num++) {
            xorAllElements ^= num;
        }
        
        // Find the rightmost set bit in the XOR result.
        // This bit helps us separate the two duplicates into different groups.
        int differingBitIndex = __builtin_ctz(xorAllElements);
        int bitMask = 1 << differingBitIndex;
        
        // 'group1Xor' and 'group2Xor' will store XOR values of two partitions.
        int group1Xor = 0, group2Xor = 0;
        
        // Partition all numbers in 'nums' using the bitMask.
        // Numbers with the bit set go into one group, others into the second group.
        for (const int& val : nums) {
            if (val & bitMask) group1Xor ^= val;
            else group2Xor ^= val;
        }
        
        // Do the same partitioning for the expected numbers (0 to originalSize - 1)
        // to remove non-duplicate values from both groups.
        for (int num = 0; num < originalSize; num++) {
            if (num & bitMask) group1Xor ^= num;
            else group2Xor ^= num;
        }
        
        // The remaining XOR values correspond to the two sneaky numbers.
        return {group1Xor, group2Xor};
    }
};
