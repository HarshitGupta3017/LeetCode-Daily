// Solution for Find Closest Person in JAVA

class Solution {
    public int findClosest(int x, int y, int z) {
        int person1diff = Math.abs(z - x);
        int person2diff = Math.abs(z - y);
        if (person1diff < person2diff) {
            return 1;
        } else if (person1diff > person2diff) {
            return 2;
        } 
        return 0;
    }
}
