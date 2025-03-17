# Solution for Divide Array Into Equal Pairs in PY

class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        mp = {}
        for num in nums:
            mp[num] = mp.get(num, 0) + 1
        for it in mp:
            if mp[it] % 2 != 0:
                return False
        return True
