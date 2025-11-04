// Solution for Find X-Sum of All K-Long Subarrays I in CPP

class Solution {
public:

    using P = pair<int, int>; // Pair to store (frequency, value)

    // Helper function to compute the x-sum for the current frequency map
    int findSum(unordered_map<int, int>& freqMap, int x) {
        // Min-heap to keep track of top 'x' most frequent elements
        // If frequencies are equal, the element with a larger value is preferred
        priority_queue<P, vector<P>, greater<P>> minHeap;

        // Insert (frequency, value) pairs into the heap
        for (const auto& [val, freq] : freqMap) {
            minHeap.push({freq, val});
            
            // Maintain only the top 'x' elements in the heap
            if (minHeap.size() > x) {
                minHeap.pop();
            }
        }

        // Calculate the x-sum based on remaining elements in the heap
        int sum = 0;
        while (!minHeap.empty()) {
            auto [freq, val] = minHeap.top();
            minHeap.pop();
            sum += freq * val;  // Each element contributes (frequency * value) to the total
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> freqMap; // Tracks frequencies in the current window
        vector<int> result;
        
        int left = 0; // Left boundary of the sliding window
        
        // Traverse the array with a sliding window of size 'k'
        for (int right = 0; right < nums.size(); right++) {
            freqMap[nums[right]]++; // Include current element in the frequency map
            
            // When the window reaches size 'k', process it
            if (right - left + 1 == k) {
                result.push_back(findSum(freqMap, x)); // Compute x-sum for current window
                
                // Remove the leftmost element as window slides forward
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]); // Clean up zero-frequency entries
                }
                left++; // Move window forward
            }
        }
        
        // Return the list of x-sums for each window
        return result;
    }
};
