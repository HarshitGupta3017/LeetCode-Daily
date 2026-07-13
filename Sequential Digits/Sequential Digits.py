# Solution for Sequential Digits in PY

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        # Seed the queue with single-digit numbers 1–8.
        # 9 is excluded because it cannot be extended.
        queue = deque(range(1, 9))
        result = []

        while queue:
            num = queue.popleft()

            # Collect numbers within the target range.
            if low <= num <= high:
                result.append(num)

            # No need to expand numbers already larger than high.
            if num > high:
                continue

            # Append the next sequential digit.
            last_digit = num % 10
            if last_digit < 9:
                queue.append(num * 10 + last_digit + 1)

        # BFS naturally generates numbers in sorted order.
        return result
