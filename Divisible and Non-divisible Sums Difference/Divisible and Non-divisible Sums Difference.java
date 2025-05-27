// Solution for Divisible and Non-divisible Sums Difference in JAVA

class Solution {
    public int differenceOfSums(int n, int m) {
        int totalSum = n * (n + 1) / 2;
        int countDivisibleByM = n / m;
        int sumDivisibleByM = m * countDivisibleByM * (countDivisibleByM + 1) / 2;
        return totalSum - 2 * sumDivisibleByM;
    }
}
