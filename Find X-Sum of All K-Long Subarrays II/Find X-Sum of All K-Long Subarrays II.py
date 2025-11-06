# Solution for Find X-Sum of All K-Long Subarrays II in PY

class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        freq = defaultdict(int)
        top = []       # stores top x (freq, val)
        rest = []      # stores remaining ones
        res = []
        curr_sum = 0

        def remove(pair):
            nonlocal curr_sum
            if pair in top:
                curr_sum -= pair[0] * pair[1]
                top.remove(pair)
                if rest:
                    largest = rest.pop()
                    curr_sum += largest[0] * largest[1]
                    insort(top, largest)
            elif pair in rest:
                rest.remove(pair)

        def insert(pair):
            nonlocal curr_sum
            if len(top) < x:
                insort(top, pair)
                curr_sum += pair[0] * pair[1]
            elif pair > top[0]:
                smallest = top.pop(0)
                curr_sum -= smallest[0] * smallest[1]
                insort(rest, smallest)
                insort(top, pair)
                curr_sum += pair[0] * pair[1]
            else:
                insort(rest, pair)

        left = 0
        for right, num in enumerate(nums):
            if freq[num] > 0:
                remove((freq[num], num))
            freq[num] += 1
            insert((freq[num], num))

            if right - left + 1 == k:
                res.append(curr_sum)
                out = nums[left]
                remove((freq[out], out))
                freq[out] -= 1
                if freq[out] > 0:
                    insert((freq[out], out))
                left += 1

        return res
