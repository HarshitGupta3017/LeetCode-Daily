// Solution for Minimum Operations to Convert All Elements to Zero in CPP

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 🧠 Stack is used to track increasing sequences of numbers
        // representing the distinct "levels" of values we still need to zero out
        // monotonic increasing stack
        stack<int> increasingStack;

        // 🧾 Variable to count total operations required
        int operationCount = 0;

        // 🔁 Iterate through each element of the array
        for (const auto& currentNum : nums) {
            
            // ⚙️ Step 1: If we encounter a smaller number, 
            // it means all larger numbers before it can't form a valid non-decreasing subarray anymore
            // So we pop them — those operations are already counted
            while (!increasingStack.empty() && increasingStack.top() > currentNum)
                increasingStack.pop();

            // ⚙️ Step 2: If current number is 0, skip (already zeroed)
            if (currentNum == 0) continue;

            // ⚙️ Step 3: If stack is empty OR top element < current number,
            // it means we found a new unique "height" that needs a fresh operation
            if (increasingStack.empty() || increasingStack.top() < currentNum) {
                increasingStack.push(currentNum);
                operationCount++;  // One new operation needed
            }
        }

        // ✅ Step 4: Return the total number of operations needed to make array all zeros
        return operationCount;
    }
};
