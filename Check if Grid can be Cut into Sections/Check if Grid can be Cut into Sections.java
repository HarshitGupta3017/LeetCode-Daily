// Solution for Check if Grid can be Cut into Sections in JAVA

class Solution {

    private int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> res = new ArrayList<>();
        res.add(intervals[0]);
        for (int i = 1; i < intervals.length; i++) {
            int[] last = res.get(res.size() - 1);
            if (intervals[i][0] < last[1]) {
                last[1] = Math.max(intervals[i][1], last[1]);
            } else {
                res.add(intervals[i]);
            }
        }
        return res.toArray(new int[res.size()][]);
    }

    public boolean checkValidCuts(int n, int[][] rectangles) {
        List<int[]> x_axis = new ArrayList<>();
        List<int[]> y_axis = new ArrayList<>();
        for (int[] rec: rectangles) {
            x_axis.add(new int[]{rec[0], rec[2]});
            y_axis.add(new int[]{rec[1], rec[3]});
        }
        int[][] mergedX = merge(x_axis.toArray(new int[x_axis.size()][]));
        if (mergedX.length >= 3) return true;
        int[][] mergedY = merge(y_axis.toArray(new int[y_axis.size()][]));
        return mergedY.length >= 3;
    }
}
