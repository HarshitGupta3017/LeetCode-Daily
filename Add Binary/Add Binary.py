# Solution for Add Binary in PY

class Solution:
    def addBinary(self, a: str, b: str) -> str:

        indexA = len(a) - 1
        indexB = len(b) - 1

        result = []
        carry = 0

        while indexA >= 0 or indexB >= 0:

            current_sum = carry

            if indexA >= 0:
                current_sum += int(a[indexA])
                indexA -= 1

            if indexB >= 0:
                current_sum += int(b[indexB])
                indexB -= 1

            result.append(str(current_sum % 2))
            carry = current_sum // 2

        if carry > 0:
            result.append('1')

        # Reverse because built from LSB → MSB
        return ''.join(reversed(result))
