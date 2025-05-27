// Solution for Divisible and Non-divisible Sums Difference in CPP

class Solution {
public:
    int differenceOfSums(int n, int m) {
        // Total sum of numbers from 1 to n using the formula: n * (n + 1) / 2
        int totalSum = n * (n + 1) / 2;

        // Count of numbers divisible by m in the range [1, n]
        int countDivisibleByM = n / m;

        // Sum of numbers divisible by m: m * (1 + 2 + ... + countDivisibleByM)
        int sumDivisibleByM = m * countDivisibleByM * (countDivisibleByM + 1) / 2;

        // Difference between numbers not divisible by m and those divisible by m
        return totalSum - 2 * sumDivisibleByM;
    }
};
