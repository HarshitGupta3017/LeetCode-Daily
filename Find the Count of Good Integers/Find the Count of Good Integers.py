# Solution for Find the Count of Good Integers in PY

class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        st = set()
        d = (n + 1) // 2
        start = pow(10, d - 1)
        end = pow(10, d) - 1

        for num in range(start, end + 1, 1):
            leftHalf = str(num)
            full = ""
            if n % 2 == 0:
                rightHalf = leftHalf[::-1]
                full = leftHalf + rightHalf
            else:
                rightHalf = leftHalf[:d - 1][::-1]
                full = leftHalf + rightHalf
            number = int(full)
            if number % k != 0:
                continue
            sortedFull = ''.join(sorted(full))
            st.add(sortedFull)

        result = 0
        factorial = [1] * 11
        for i in range(1, 11):
            factorial[i] = factorial[i - 1] * i

        for s in st:
            count = [0] * 10
            for ch in s:
                count[int(ch)] += 1
            totalDigits = len(s)
            zeroDigits = count[0]
            nonZeroDigits = totalDigits - zeroDigits
            perm = (nonZeroDigits * factorial[totalDigits - 1])
            for i in range(10):
                perm //= factorial[count[i]]
            result += perm

        return result
