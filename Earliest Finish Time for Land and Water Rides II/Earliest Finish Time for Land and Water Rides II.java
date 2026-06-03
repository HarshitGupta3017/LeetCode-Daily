// Solution for Earliest Finish Time for Land and Water Rides II in JAVA

class Solution {
    private void solve(int[] s1, int[] d1, int[] s2, int[] d2, int[] ans) {
        int firstFinish = Integer.MAX_VALUE;

        for (int i = 0; i < s1.length; i++)
            firstFinish = Math.min(firstFinish, s1[i] + d1[i]);

        for (int j = 0; j < s2.length; j++)
            ans[0] = Math.min(ans[0], Math.max(firstFinish, s2[j]) + d2[j]);
    }

    public int earliestFinishTime(int[] landStartTime, int[] landDuration,
                                  int[] waterStartTime, int[] waterDuration) {
        int[] ans = {Integer.MAX_VALUE};

        solve(landStartTime, landDuration, waterStartTime, waterDuration, ans);
        solve(waterStartTime, waterDuration, landStartTime, landDuration, ans);

        return ans[0];
    }
}
