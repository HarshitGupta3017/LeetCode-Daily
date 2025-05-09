// Solution for Count Number of Balanced Permutations in CPP

class Solution {
public:
    int n, totalDigitSum;
    int MOD = 1e9 + 7;
    long long totalPermPossible = 0;

    int findPower(long long a, long long b) {
        if (b == 0)
            return 1;
        long long half = findPower(a, b / 2);
        long long res = (half * half) % MOD;
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        return res;
    }

    int solve(int digit, int evenIdxDigitsCount, int currSum, 
                vector<int>& freq, vector<long long>& fermatFact,
                vector<vector<vector<int>>>& t) {
        if (digit == 10) {
            return (currSum == totalDigitSum/2 && evenIdxDigitsCount == (n+1)/2) ? totalPermPossible : 0;
        }
        if (t[digit][evenIdxDigitsCount][currSum] != -1) {
            return t[digit][evenIdxDigitsCount][currSum];
        }
        long long ways = 0;
        for (int count = 0; count <= min(freq[digit], (n+1)/2 - evenIdxDigitsCount); count++) {
            int evenPosCount = count;
            int oddPosCount = freq[digit] - count;
            // finding duplicates / denominator (1/x)!
            long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount]) % MOD;
            long long val = solve(digit + 1, evenIdxDigitsCount + evenPosCount, currSum + digit*count, freq, fermatFact, t);
            ways = (ways + (val * div) % MOD) % MOD;
        }
        return t[digit][evenIdxDigitsCount][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        n = num.length();
        totalDigitSum = 0;
        vector<int> freq(10, 0);
        for (int i = 0; i < n; i++) {
            totalDigitSum += num[i] - '0';
            freq[num[i] - '0']++;
        }
        if (totalDigitSum % 2 == 1) 
            return 0;
        
        // Precomputing factorial
        vector<long long> fact(n + 1, 1);
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // Precomputing inverse factorial (1 / x)!
        vector<long long> fermatFact(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(fact[i], MOD - 2) % MOD;
        }

        totalPermPossible = (1LL * fact[(n+1)/2] * fact[n/2]) % MOD;
        int digit = 0;
        int evenIdxDigitsCount = 0;
        int currSum = 0;
        vector<vector<vector<int>>> t(10, vector<vector<int>>((n + 1) / 2 + 1, vector<int>(totalDigitSum + 1, -1)));
        return solve(digit, evenIdxDigitsCount, currSum, freq, fermatFact, t);
    }
};
