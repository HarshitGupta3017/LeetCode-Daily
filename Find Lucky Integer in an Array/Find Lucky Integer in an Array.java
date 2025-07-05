// Solution for Find Lucky Integer in an Array in JAVA

class Solution {
    public int findLucky(int[] arr) {
        int n = arr.length;
        for (int num : arr) {
            int value = num & 65535;
            if (value <= n) {
                arr[value - 1] += (1 << 16);
            }
        }
        for (int val = n; val >= 1; val--) {
            int freq = arr[val - 1] >> 16;
            if (freq == val) {
                return val;
            }
        }
        return -1;
    }
}
