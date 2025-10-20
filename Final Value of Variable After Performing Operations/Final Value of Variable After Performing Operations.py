# Solution for Final Value of Variable After Performing Operations in PY

class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return sum(1 if o[1] == '+' else -1 for o in operations)
