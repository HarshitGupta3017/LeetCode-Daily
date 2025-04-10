// Solution for Count the Number of Powerful Integers in JAVA

class Solution {

    private long solve(String str, String suff, int limit) {
        if (str.length() < suff.length()) return 0;

        long count = 0;
        String trailStr = str.substring(str.length() - suff.length());
        int remL = str.length() - suff.length();

        for (int i = 0; i < remL; i++) {
            int digit = str.charAt(i) - '0';
            if (digit <= limit) {
                count += digit * Math.pow(limit + 1, remL - i - 1);
            } else {
                count += Math.pow(limit + 1, remL - i);
                return count;
            }
        }

        if (trailStr.compareTo(suff) >= 0) {
            count += 1;
        }

        return count;
    }

    public long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        String startStr = Long.toString(start - 1);
        String finishStr = Long.toString(finish);
        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
}
