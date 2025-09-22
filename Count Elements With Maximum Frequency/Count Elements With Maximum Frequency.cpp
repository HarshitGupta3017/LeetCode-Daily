// Solution for Count Elements With Maximum Frequency in CPP

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Frequency array for numbers in range [1..100]
        vector<int> frequency(101, 0);

        int maxFrequency = 0;   // Track highest frequency of any element
        int totalCount = 0;     // Track sum of frequencies of all elements with max frequency

        for (int num : nums) {
            // Increase count for this number
            frequency[num]++;

            // If this number becomes the new max frequency
            if (frequency[num] > maxFrequency) {
                maxFrequency = frequency[num];     // Update highest frequency
                totalCount = maxFrequency;         // Reset totalCount to this frequency
            }
            // If this number just matched the current max frequency
            else if (frequency[num] == maxFrequency) {
                totalCount += maxFrequency;        // Add its contribution
            }
        }

        return totalCount;
    }
};
