// Solution for Total Characters in String After Transformations I in CPP

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        vector<long long> cnt(26, 0);
        for (char ch: s) {
            cnt[ch - 'a']++;
        }
        for (int layer = 0; layer < t; layer++) {
            vector<long long> nxt_cnt(26, 0);
            for (int i = 0; i < 25; i++) {
                nxt_cnt[i + 1] = (nxt_cnt[i + 1] + cnt[i]) % MOD;
            }
            nxt_cnt[0] = (nxt_cnt[0] + cnt[25]) % MOD;
            nxt_cnt[1] = (nxt_cnt[1] + cnt[25]) % MOD;
            cnt = nxt_cnt;
        }
        long long res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + cnt[i]) % MOD;
        }
        return res;
    }
};
