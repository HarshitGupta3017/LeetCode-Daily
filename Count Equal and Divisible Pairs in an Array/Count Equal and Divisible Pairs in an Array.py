# Solution for Count Equal and Divisible Pairs in an Array in PY

class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        mp = defaultdict(list)
        count = 0
        for i in range(len(nums)):
            num = nums[i]
            if num in mp:
                for prev_idx in mp[num]:
                    if (prev_idx * i) % k == 0:
                        count += 1
            mp[num].append(i)
        return count
