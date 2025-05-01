# Solution for Maximum Number of Tasks You Can Assign in PY

class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        tasks.sort()
        workers.sort()

        def check(mid: int) -> bool:
            sorted_workers = workers[-mid:]  # Get the strongest 'mid' workers
            multiset = Counter(sorted_workers)
            # sorted_workers = sorted(multiset.elements())
            pills_used = 0
            for i in range(mid - 1, -1, -1):
                task = tasks[i]
                # Try without pill
                if sorted_workers and sorted_workers[-1] >= task:
                    w = sorted_workers.pop()  # Use strongest
                    multiset[w] -= 1
                    if multiset[w] == 0:
                        del multiset[w]
                # Try with pill
                elif pills_used < pills:
                    idx = bisect.bisect_left(sorted_workers, task - strength)
                    if idx == len(sorted_workers):
                        return False
                    w = sorted_workers.pop(idx)
                    multiset[w] -= 1
                    if multiset[w] == 0:
                        del multiset[w]
                    pills_used += 1
                else:
                    return False
            return True

        left, right, res = 0, min(len(tasks), len(workers)), 0
        while left <= right:
            mid = (left + right) // 2
            if check(mid):
                res = mid
                left = mid + 1
            else:
                right = mid - 1
        return res
