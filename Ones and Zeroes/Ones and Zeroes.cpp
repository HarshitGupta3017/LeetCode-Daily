// Solution for Ones and Zeroes in CPP

class Solution {
public:
    // 🔹 Recursive helper function with memoization
    // Purpose: Returns the maximum subset size achievable using strings[i...end]
    // while having at most 'm' zeros and 'n' ones left.
    int solve(vector<pair<int, int>>& zeroOneCount, int m, int n, int index,
              vector<vector<vector<int>>>& dpMemo) {

        // 🧩 Base case: If we've processed all strings OR no capacity remains
        if (index >= zeroOneCount.size() || (m == 0 && n == 0))
            return 0;

        // ⚙️ Return precomputed value if already solved
        if (dpMemo[m][n][index] != -1)
            return dpMemo[m][n][index];

        int takeCurrent = 0;

        // ✅ Option 1: Take current string if it fits within remaining zeros & ones
        if (zeroOneCount[index].first <= m && zeroOneCount[index].second <= n) {
            takeCurrent = 1 + solve(
                zeroOneCount,
                m - zeroOneCount[index].first,  // reduce available zeros
                n - zeroOneCount[index].second, // reduce available ones
                index + 1,                      // move to next string
                dpMemo
            );
        }

        // 🚫 Option 2: Skip current string
        int skipCurrent = solve(zeroOneCount, m, n, index + 1, dpMemo);

        // 🧮 Store the best of both options and return
        return dpMemo[m][n][index] = max(takeCurrent, skipCurrent);
    }

    // 🔹 Main function to find the largest subset that fits within given 0's and 1's
    int findMaxForm(vector<string>& strs, int m, int n) {
        int totalStrings = strs.size();

        // 🧾 Step 1️⃣: Precompute zero & one counts for each string
        vector<pair<int, int>> zeroOneCount(totalStrings);
        for (int i = 0; i < totalStrings; i++) {
            int zeros = count(strs[i].begin(), strs[i].end(), '0');
            int ones  = count(strs[i].begin(), strs[i].end(), '1');
            zeroOneCount[i] = {zeros, ones};
        }

        // 🧠 Step 2️⃣: Initialize 3D DP memo array
        // Dimensions: [m+1][n+1][totalStrings]
        // dpMemo[m][n][i] = max subset size using strings[i...end]
        vector<vector<vector<int>>> dpMemo(m + 1, vector<vector<int>>(n + 1, vector<int>(totalStrings, -1)));

        // 🏁 Step 3️⃣: Start recursive exploration from first string
        return solve(zeroOneCount, m, n, 0, dpMemo);
    }
};
