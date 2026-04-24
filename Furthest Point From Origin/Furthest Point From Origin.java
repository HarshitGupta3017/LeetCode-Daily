// Solution for Furthest Point From Origin in JAVA

class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int L = 0, R = 0, blank = 0;
        for (char ch : moves.toCharArray()) {
            if (ch == 'L') L++;
            else if (ch == 'R') R++;
            else blank++;
        }
        return Math.abs(L - R) + blank;
    }
}
