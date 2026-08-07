# Solution for Smallest Divisible Digit Product II in PY

class Solution:
    def buildSuffix(self, required: int, slots: int) -> str:
        suffix = []

        for digit in range(9, 1, -1):
            while required % digit == 0:
                suffix.append(str(digit))
                required //= digit

        if required != 1:
            suffix.append('X')  # sentinel

        while len(suffix) < slots:
            suffix.append('1')

        suffix.reverse()
        return "".join(suffix)

    def smallestNumber(self, num: str, t: int) -> str:
        n = len(num)

        remaining = t
        for p in (2, 3, 5, 7):
            while remaining % p == 0:
                remaining //= p

        if remaining != 1:
            return "-1"

        remainingFactor = [t] * (n + 1)

        for i in range(n):
            digit = int(num[i])

            if digit == 0:
                break

            remainingFactor[i + 1] = (
                remainingFactor[i] //
                gcd(remainingFactor[i], digit)
            )

        if remainingFactor[n] == 1:
            return num

        firstZero = num.find('0')
        searchUpTo = firstZero if firstZero != -1 else n - 1

        for i in range(searchUpTo, -1, -1):
            neededFactor = remainingFactor[i]
            freeSlots = n - 1 - i

            for digit in range(int(num[i]) + 1, 10):
                factorAfterDigit = (
                    neededFactor //
                    gcd(neededFactor, digit)
                )

                suffix = self.buildSuffix(factorAfterDigit, freeSlots)

                if len(suffix) == freeSlots:
                    return num[:i] + str(digit) + suffix

        return self.buildSuffix(t, n + 1)
