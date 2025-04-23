# Solution for Count Largest Group in PY

class Solution:

    def findDS(self, num: int) -> int:
        sum = 0
        while num != 0:
            sum += num % 10
            num //= 10
        return sum

    def countLargestGroup(self, n: int) -> int:
        mp = defaultdict(int)
        count, maxSize = 0, 0
        for num in range(1, n + 1):
            digitSum = self.findDS(num)
            mp[digitSum] += 1
            if mp[digitSum] == maxSize:
                count += 1
            elif mp[digitSum] > maxSize:
                maxSize = mp[digitSum]
                count = 1
        return count
