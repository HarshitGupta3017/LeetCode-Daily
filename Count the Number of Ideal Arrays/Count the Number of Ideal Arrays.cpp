// Solution for Count the Number of Ideal Arrays in CPP

class Solution {
public:
    int M = 1e9 + 7;
    void findSets(int m, vector<int>& count, vector<vector<int>>& dp) {
        if (dp[m][1] != 0) return;
        dp[m][1] = 1;
        count[1]++;
        for (int div = 2; div <= m; div++) {
            if (m % div == 0) {
                findSets(m / div, count, dp);
                for (int len = 1; len < 15; len++) {
                    if (dp[m / div][len] != 0) {
                        dp[m][len + 1] += dp[m / div][len];
                        count[len + 1] += dp[m / div][len];
                    }
                }
            }
        }
    }

    int findPower(long long a, long long b) {
        if (b == 0) return 1;
        long long half = findPower(a, b / 2);
        long long result = (half * half) % M;
        if (b % 2 == 1) {
            result = (result * a) % M;
        }
        return result;
    }

    int modularnCr(int n, int r, vector<long long>& fact) {
        if (r < 0 || r > n) return 0;
        long long a = fact[n];
        long long b = (fact[r] * fact[n - r]) % M;
        return (a * findPower(b, M - 2)) % M;
    }

    int idealArrays(int n, int maxValue) {
        vector<vector<int>> dp(maxValue + 1, vector<int>(15, 0));
        vector<int> count(15, 0);

        // find sets count
        for (int val = 1; val <= maxValue; val++) {
            findSets(val, count, dp);
        }

        // Precompute factorial
        vector<long long> fact(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % M;
        }

        long long result = 0;
        for (int len = 1; len < 15; len++) {
            if (n < len) break;
            if (count[len] != 0) {
                long long possibilities = modularnCr(n - 1, len - 1, fact);
                result = (result + (count[len] * possibilities) % M) % M;
            }
        }
        return (int)result;
    }
};
