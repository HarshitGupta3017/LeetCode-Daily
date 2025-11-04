# Solution for Find X-Sum of All K-Long Subarrays I in PY

class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        
        def findSum(freqMap):
            # Min-heap to keep top x frequent elements
            minHeap = []
            
            for val, freq in freqMap.items():
                heapq.heappush(minHeap, (freq, val))
                
                # Maintain only top x elements
                if len(minHeap) > x:
                    heapq.heappop(minHeap)
            
            # Compute x-sum = Σ(freq * val)
            return sum(freq * val for freq, val in minHeap)
        
        freqMap = defaultdict(int)
        result = []
        left = 0
        
        # Sliding window of size k
        for right, num in enumerate(nums):
            freqMap[num] += 1
            
            if right - left + 1 == k:
                result.append(findSum(freqMap))
                
                # Slide the window: remove leftmost element
                freqMap[nums[left]] -= 1
                if freqMap[nums[left]] == 0:
                    del freqMap[nums[left]]
                left += 1
        
        return result
