# Solution for Apply Operations to Maximize Score in PY

class Solution:
    MOD = int(1e9 + 7)

    def findPower(self, a: int, b: int) -> int:
        if b == 0:
            return 1
        half = self.findPower(a, b // 2)
        result = (half * half) % self.MOD
        if b % 2 == 1:
            result = (result * a) % self.MOD
        return result

    def getPrimes(self, limit: int) -> List[int]:
        isPrime = [True] * (limit + 1)
        primes = []
        for i in range(2, int(limit ** 0.5) + 1):
            if isPrime[i]:
                for j in range(i * i, limit + 1, i):
                    isPrime[j] = False
        for i in range(2, limit + 1):
            if isPrime[i]:
                primes.append(i)
        return primes

    def findPrimeScores(self, nums: List[int]) -> List[int]:
        n = len(nums)
        primeScores = [0] * n
        maxEle = max(nums)
        primes = self.getPrimes(maxEle)
        
        for i in range(n):
            num = nums[i]
            for prime in primes:
                if prime * prime > num:
                    break
                if num % prime != 0:
                    continue
                primeScores[i] += 1
                while num % prime == 0:
                    num //= prime
            if num > 1:
                primeScores[i] += 1
        return primeScores

    def findNextGreater(self, primeScores: List[int]) -> List[int]:
        n = len(primeScores)
        nextGreater = [n] * n
        stack = []
        
        for i in range(n - 1, -1, -1):
            while stack and primeScores[stack[-1]] <= primeScores[i]:
                stack.pop()
            if stack:
                nextGreater[i] = stack[-1]
            stack.append(i)
        return nextGreater

    def findPrevGreater(self, primeScores: List[int]) -> List[int]:
        n = len(primeScores)
        prevGreater = [-1] * n
        stack = []
        
        for i in range(n):
            while stack and primeScores[stack[-1]] < primeScores[i]:
                stack.pop()
            if stack:
                prevGreater[i] = stack[-1]
            stack.append(i)
        return prevGreater

    def maximumScore(self, nums: List[int], k: int) -> int:
        primeScores = self.findPrimeScores(nums)
        nextGreater = self.findNextGreater(primeScores)
        prevGreater = self.findPrevGreater(primeScores)
        
        n = len(nums)
        subarrays = [0] * n
        for i in range(n):
            subarrays[i] = (nextGreater[i] - i) * (i - prevGreater[i])
        
        sortedNums = sorted([(nums[i], i) for i in range(n)])
        
        score = 1
        idx = n - 1
        while k > 0:
            num, i = sortedNums[idx]
            idx -= 1
            ops = min(k, subarrays[i])
            score = (score * self.findPower(num, ops)) % self.MOD
            k -= ops
        
        return score
