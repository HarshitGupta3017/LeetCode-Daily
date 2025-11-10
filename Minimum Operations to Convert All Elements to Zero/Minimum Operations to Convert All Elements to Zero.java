// Solution for Minimum Operations to Convert All Elements to Zero in JAVA

class Solution {
    public int minOperations(int[] nums) {
        // 🧠 Stack to track increasing sequences of numbers
        // representing distinct "levels" that still need to be zeroed out
        Stack<Integer> increasingStack = new Stack<>();

        // 🧾 Count total operations required
        int operationCount = 0;

        // 🔁 Iterate through each number
        for (int currentNum : nums) {
            
            // ⚙️ Step 1: If current number is smaller, 
            // previous higher levels are no longer valid — pop them
            while (!increasingStack.isEmpty() && increasingStack.peek() > currentNum) {
                increasingStack.pop();
            }

            // ⚙️ Step 2: Skip zeros (already zeroed)
            if (currentNum == 0) continue;

            // ⚙️ Step 3: If stack empty or top < current number,
            // new height found → new operation needed
            if (increasingStack.isEmpty() || increasingStack.peek() < currentNum) {
                increasingStack.push(currentNum);
                operationCount++;
            }
        }

        // ✅ Return total operations needed to make all elements zero
        return operationCount;
    }
}
