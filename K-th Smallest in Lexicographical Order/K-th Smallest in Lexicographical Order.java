// Solution for K-th Smallest in Lexicographical Order in JAVA

class Solution {
    public int countNumbersWithPrefix(long prefix, long nextPrefix, int n) {
        int totalCount = 0;
        while (prefix <= n) {
            totalCount += Math.min((long) n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return totalCount;
    }

    public int findKthNumber(int n, int k) {
        int current = 1;
        k--;

        while (k > 0) {
            int count = countNumbersWithPrefix(current, current + 1, n);
            if (count <= k) {
                current++;
                k -= count;
            } else {
                current *= 10;
                k--;
            }
        }

        return current;
    }
}
