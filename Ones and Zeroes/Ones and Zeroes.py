# Solution for Ones and Zeroes in PY

class Solution:
    # 🔹 Recursive helper with memoization
    def solve(self, zero_one_count, m, n, index, dp_memo):
        # 🧩 Base case: processed all strings or capacity exhausted
        if index >= len(zero_one_count) or (m == 0 and n == 0):
            return 0

        # ⚙️ Return cached result if computed
        if dp_memo[m][n][index] != -1:
            return dp_memo[m][n][index]

        take_current = 0
        zeros, ones = zero_one_count[index]

        # ✅ Option 1: Take current string if it fits
        if zeros <= m and ones <= n:
            take_current = 1 + self.solve(
                zero_one_count,
                m - zeros,
                n - ones,
                index + 1,
                dp_memo
            )

        # 🚫 Option 2: Skip current string
        skip_current = self.solve(zero_one_count, m, n, index + 1, dp_memo)

        # 🧮 Store and return best of both choices
        dp_memo[m][n][index] = max(take_current, skip_current)
        return dp_memo[m][n][index]

    # 🔹 Main function
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        total_strings = len(strs)

        # 🧾 Step 1️⃣: Precompute zero & one counts
        zero_one_count = []
        for s in strs:
            zeros = s.count('0')
            ones = s.count('1')
            zero_one_count.append((zeros, ones))

        # 🧠 Step 2️⃣: Initialize 3D DP memo array
        dp_memo = [[[-1] * total_strings for _ in range(n + 1)] for _ in range(m + 1)]

        # 🏁 Step 3️⃣: Start recursion
        return self.solve(zero_one_count, m, n, 0, dp_memo)
