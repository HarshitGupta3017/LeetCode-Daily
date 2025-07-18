// Solution for Minimum Difference in Sums After Removal of Elements in CPP

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();        // Total size of array = 3n
        int n = N / 3;              // Size of each group

        // Arrays to store prefix (left) and suffix (right) results
        vector<long long> leftMinSum(N, 0);   // Stores minimum sum of n elements from left to i
        vector<long long> rightMaxSum(N, 0);  // Stores maximum sum of n elements from right to i

        // -----------------------
        // Step 1: Left -> Right
        // -----------------------
        priority_queue<int> maxHeap;  // Max-heap to remove largest numbers and keep smallest n
        long long leftSum = 0;

        for (int i = 0; i < 2 * n; i++) {
            maxHeap.push(nums[i]);   // Add current number to heap
            leftSum += nums[i];      // Add to running sum

            // Maintain only the smallest n elements in the heap
            if (maxHeap.size() > n) {
                leftSum -= maxHeap.top(); // Remove the largest to keep smallest n
                maxHeap.pop();
            }

            // Store current smallest n elements' sum ending at i
            leftMinSum[i] = leftSum;
        }

        // -----------------------
        // Step 2: Right -> Left
        // -----------------------
        priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to remove smallest and keep largest n
        long long rightSum = 0;

        for (int i = N - 1; i >= n; i--) {
            minHeap.push(nums[i]);   // Add current number to heap
            rightSum += nums[i];     // Add to running sum

            // Maintain only the largest n elements in the heap
            if (minHeap.size() > n) {
                rightSum -= minHeap.top();  // Remove the smallest to keep largest n
                minHeap.pop();
            }

            // Store current largest n elements' sum starting at i
            rightMaxSum[i] = rightSum;
        }

        // -----------------------
        // Step 3: Compute Result
        // -----------------------
        long long result = LLONG_MAX;

        // We try every possible split point between left part [0...i] and right part [i+1...N-1]
        // where both have size n
        for (int i = n - 1; i < 2 * n; i++) {
            // Difference = sum(first n elements) - sum(second n elements)
            long long diff = leftMinSum[i] - rightMaxSum[i + 1];

            // Update the minimum difference
            result = min(result, diff);
        }

        return result;
    }
};
