# Solution for Minimum Domino Rotations For Equal Row in PY

class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def find(val: int) -> int:
            swapTop, swapBot = 0, 0
            for i in range(len(tops)):
                if tops[i] != val and bottoms[i] != val:
                    return -1
                elif tops[i] != val:
                    swapTop += 1
                elif bottoms[i] != val:
                    swapBot += 1
            return min(swapTop, swapBot)
        
        res = sys.maxsize
        for val in range(1, 7):
            steps = find(val)
            if (steps != -1):
                res = min(res, steps)
        return -1 if res == sys.maxsize else res
