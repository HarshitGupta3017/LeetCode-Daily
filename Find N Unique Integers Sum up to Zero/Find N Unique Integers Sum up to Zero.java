// Solution for Find N Unique Integers Sum up to Zero in JAVA

class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        int idx = 0;
        
        for (int num = -(n / 2); num <= (n / 2); num++) {
            if (num == 0 && n % 2 == 0) continue;
            result[idx++] = num;
        }
        
        return result;
    }
}
