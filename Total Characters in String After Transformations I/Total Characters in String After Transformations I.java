// Solution for Total Characters in String After Transformations I in JAVA

class Solution {
    public int lengthAfterTransformations(String s, int t) {
        int MOD = 1000000007;
        long[] cnt = new long[26];
        for (char ch: s.toCharArray()) {
            cnt[ch - 'a']++;
        }
        for (int layer = 0; layer < t; layer++) {
            long[] nxt_cnt = new long[26];
            for (int i = 0; i < 25; i++) {
                nxt_cnt[i + 1] = (nxt_cnt[i + 1] + cnt[i]) % MOD;
            }
            nxt_cnt[0] = (nxt_cnt[0] + cnt[25]) % MOD;
            nxt_cnt[1] = (nxt_cnt[1] + cnt[25]) % MOD;
            cnt = nxt_cnt;
        }
        long res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + cnt[i]) % MOD;
        }
        return (int)res;
    }
}
