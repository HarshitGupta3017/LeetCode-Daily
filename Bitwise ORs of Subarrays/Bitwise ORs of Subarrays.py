# Solution for Bitwise ORs of Subarrays in PY

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        prevOrs = set()
        currOrs = set()
        distinctOrs = set()

        for i in range(len(arr)):
            currOrs.add(arr[i])
            distinctOrs.add(arr[i])

            for prevVal in prevOrs:
                newOr = prevVal | arr[i]
                currOrs.add(newOr)
                distinctOrs.add(newOr)

            prevOrs = currOrs.copy()
            currOrs.clear()

        return len(distinctOrs)
