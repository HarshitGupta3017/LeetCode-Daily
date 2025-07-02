# Solution for Find the Original Typed String II in PY

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        MOD = 10**9 + 7
        n = len(word)
        if k > n:
            return 0

        # Step 1: Count consecutive character groups
        group_freq = []
        freq = 1
        for i in range(1, n):
            if word[i] == word[i - 1]:
                freq += 1
            else:
                group_freq.append(freq)
                freq = 1
        group_freq.append(freq)  # Add last group

        group_count = len(group_freq)

        # Step 2: Total ways = product of all group sizes
        total_ways = 1
        for f in group_freq:
            total_ways = (total_ways * f) % MOD

        if group_count >= k:
            return total_ways

        # Step 3: DP to subtract invalid combinations
        dp = [[0] * (k + 1) for _ in range(group_count + 1)]

        for length in range(k - 1, -1, -1):
            dp[group_count][length] = 1

        for i in range(group_count - 1, -1, -1):
            prefix = [0] * (k + 2)
            for j in range(1, k + 1):
                prefix[j] = (prefix[j - 1] + dp[i + 1][j - 1]) % MOD

            for length in range(k - 1, -1, -1):
                min_len = length + 1
                max_len = length + group_freq[i]
                if max_len >= k:
                    max_len = k - 1

                if min_len <= max_len:
                    dp[i][length] = (prefix[max_len + 1] - prefix[min_len] + MOD) % MOD

        invalid_ways = dp[0][0]
        return (total_ways - invalid_ways + MOD) % MOD
