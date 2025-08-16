# Solution for Maximum 69 Number in PY

class Solution:
    def maximum69Number(self, num: int) -> int:
        tempNum = num
        digitPosition = 0
        leftmostSixPosition = -1

        while tempNum > 0:
            currentDigit = tempNum % 10
            if currentDigit == 6:
                leftmostSixPosition = digitPosition
            tempNum //= 10
            digitPosition += 1

        return num if leftmostSixPosition == -1 else num + 3 * (10 ** leftmostSixPosition)
