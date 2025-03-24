// Solution for Count Days Without Meetings in JAVA

class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        int res = 0;
        int merge_end = 0;
        for (int[] meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            if (start > merge_end + 1) {
                res += (start - merge_end - 1);
            }
            merge_end = Math.max(merge_end, end);
        }
        if (merge_end < days) {
            res += days - merge_end;
        }
        return res;
    }
}
