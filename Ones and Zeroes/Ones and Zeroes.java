// Solution for Ones and Zeroes in JAVA

class Solution {

    // 🔹 Recursive helper with memoization
    private int solve(List<int[]> zeroOneCount, int m, int n, int index, int[][][] dpMemo) {
        // 🧩 Base case: all strings processed or no capacity left
        if (index >= zeroOneCount.size() || (m == 0 && n == 0))
            return 0;

        // ⚙️ Return precomputed value if already solved
        if (dpMemo[m][n][index] != -1)
            return dpMemo[m][n][index];

        int takeCurrent = 0;
        int[] current = zeroOneCount.get(index);

        // ✅ Option 1: Take current string if fits
        if (current[0] <= m && current[1] <= n) {
            takeCurrent = 1 + solve(
                zeroOneCount,
                m - current[0],   // reduce available zeros
                n - current[1],   // reduce available ones
                index + 1,        // move to next string
                dpMemo
            );
        }

        // 🚫 Option 2: Skip current string
        int skipCurrent = solve(zeroOneCount, m, n, index + 1, dpMemo);

        // 🧮 Store and return the best of both choices
        return dpMemo[m][n][index] = Math.max(takeCurrent, skipCurrent);
    }

    // 🔹 Main function
    public int findMaxForm(String[] strs, int m, int n) {
        int totalStrings = strs.length;

        // 🧾 Step 1️⃣: Precompute zero & one counts for each string
        List<int[]> zeroOneCount = new ArrayList<>();
        for (String s : strs) {
            int zeros = 0, ones = 0;
            for (char ch : s.toCharArray()) {
                if (ch == '0') zeros++;
                else ones++;
            }
            zeroOneCount.add(new int[]{zeros, ones});
        }

        // 🧠 Step 2️⃣: Initialize 3D DP memo array
        int[][][] dpMemo = new int[m + 1][n + 1][totalStrings];
        for (int[][] arr2D : dpMemo)
            for (int[] arr1D : arr2D)
                Arrays.fill(arr1D, -1);

        // 🏁 Step 3️⃣: Start recursion
        return solve(zeroOneCount, m, n, 0, dpMemo);
    }
}
