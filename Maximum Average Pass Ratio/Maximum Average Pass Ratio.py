# Solution for Maximum Average Pass Ratio in PY

class Solution:
    def maxAverageRatio(self, classes, extraStudents):
        def delta(p, t):
            return (p + 1) / (t + 1) - p / t

        # Max-heap (negating delta since heapq is min-heap)
        pq = [(-delta(p, t), p, t) for p, t in classes]
        heapq.heapify(pq)

        # Distribute extra students
        for _ in range(extraStudents):
            gain, p, t = heapq.heappop(pq)
            p += 1
            t += 1
            heapq.heappush(pq, (-delta(p, t), p, t))

        # Compute final result
        result = 0
        for _, p, t in pq:
            result += p / t

        return result / len(classes)
