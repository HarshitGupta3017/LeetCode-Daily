// Solution for Number of Laser Beams in a Bank in JAVA

class Solution {
    public int numberOfBeams(String[] bank) {
        int beams = 0, prev = 0;
        for (String row : bank) {
            int curr = 0;
            for (char c : row.toCharArray()) if (c == '1') curr++;
            if (curr > 0) {
                beams += prev * curr;
                prev = curr;
            }
        }
        return beams;
    }
}
