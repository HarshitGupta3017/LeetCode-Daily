# Solution for Minimum Operations to Convert All Elements to Zero in PY

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        # 🧠 Stack to track increasing sequences of numbers
        # representing distinct "levels" that still need to be zeroed out
        increasing_stack = []

        # 🧾 Count total operations
        operation_count = 0

        # 🔁 Iterate through each number
        for current_num in nums:
            
            # ⚙️ Step 1: If smaller number appears, 
            # pop higher numbers from stack
            while increasing_stack and increasing_stack[-1] > current_num:
                increasing_stack.pop()

            # ⚙️ Step 2: Skip zeros
            if current_num == 0:
                continue

            # ⚙️ Step 3: If stack empty or top < current number,
            # new height found → new operation
            if not increasing_stack or increasing_stack[-1] < current_num:
                increasing_stack.append(current_num)
                operation_count += 1

        # ✅ Return total operations needed to make array zero
        return operation_count
