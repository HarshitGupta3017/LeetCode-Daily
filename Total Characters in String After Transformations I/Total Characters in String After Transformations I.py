# Solution for Total Characters in String After Transformations I in PY

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        MOD = 1000000007
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - ord('a')] += 1

        for layer in range(t):
            nxt_cnt = [0] * 26
            for i in range(25):
                nxt_cnt[i + 1] = (nxt_cnt[i + 1] + cnt[i]) % MOD
            nxt_cnt[0] = (nxt_cnt[0] + cnt[25]) % MOD
            nxt_cnt[1] = (nxt_cnt[1] + cnt[25]) % MOD
            cnt = nxt_cnt

        return sum(cnt) % MOD
