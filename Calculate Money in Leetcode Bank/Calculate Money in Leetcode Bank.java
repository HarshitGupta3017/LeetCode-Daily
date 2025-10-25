// Solution for Calculate Money in Leetcode Bank in JAVA

class Solution {
    public int totalMoney(int n) {
        // Step 1️⃣: Calculate number of complete weeks
        int fullWeeks = n / 7;

        // Step 2️⃣: Compute total for all full weeks (arithmetic sequence: 28, 35, 42, ...)
        int firstWeekSum = 28;                      // 1+2+3+4+5+6+7 = 28
        int lastWeekSum = 28 + (fullWeeks - 1) * 7; // Each week adds +7 total
        int totalFullWeeks = fullWeeks * (firstWeekSum + lastWeekSum) / 2;

        // Step 3️⃣: Handle remaining days
        int remainingDays = n % 7;
        int startValue = 1 + fullWeeks;             // Starting deposit for next week
        int endValue = startValue + remainingDays - 1;
        int totalPartialWeek = remainingDays * (startValue + endValue) / 2;

        // Step 4️⃣: Return total
        return totalFullWeeks + totalPartialWeek;
    }
}
