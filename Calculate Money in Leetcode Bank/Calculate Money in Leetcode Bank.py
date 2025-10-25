# Solution for Calculate Money in Leetcode Bank in PY

class Solution:
    def totalMoney(self, n: int) -> int:
        # Step 1️⃣: Full weeks
        fullWeeks = n // 7

        # Step 2️⃣: Total from complete weeks (28, 35, 42, ...)
        firstWeekSum = 28
        lastWeekSum = 28 + (fullWeeks - 1) * 7 if fullWeeks > 0 else 0
        totalFullWeeks = fullWeeks * (firstWeekSum + lastWeekSum) // 2

        # Step 3️⃣: Remaining days
        remainingDays = n % 7
        startValue = 1 + fullWeeks
        endValue = startValue + remainingDays - 1
        totalPartialWeek = remainingDays * (startValue + endValue) // 2

        # Step 4️⃣: Final total
        return totalFullWeeks + totalPartialWeek
