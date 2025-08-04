# Solution for Fruit Into Baskets in PY

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        from collections import defaultdict

        fruitCount = defaultdict(int)
        windowStart = 0
        maxFruitsCollected = 0

        for windowEnd in range(len(fruits)):
            fruitCount[fruits[windowEnd]] += 1

            while len(fruitCount) > 2:
                fruitCount[fruits[windowStart]] -= 1
                if fruitCount[fruits[windowStart]] == 0:
                    del fruitCount[fruits[windowStart]]
                windowStart += 1

            maxFruitsCollected = max(maxFruitsCollected, windowEnd - windowStart + 1)

        return maxFruitsCollected
