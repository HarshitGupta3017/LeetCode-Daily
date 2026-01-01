# Solution for Plus One in PY

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1

        # Traverse from right to left
        for i in range(len(digits) - 1, -1, -1):
            current_sum = digits[i] + carry
            digits[i] = current_sum % 10
            carry = current_sum // 10

        # If carry remains, insert at beginning
        if carry == 1:
            digits.insert(0, 1)

        return digits
