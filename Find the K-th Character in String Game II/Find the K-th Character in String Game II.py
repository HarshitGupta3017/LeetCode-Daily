# Solution for Find the K-th Character in String Game II in PY

class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        if k == 1:
            return 'a'

        current_length = 1
        reduced_k = -1
        operation_type = 0

        for i in range(len(operations)):
            current_length *= 2
            if current_length >= k:
                operation_type = operations[i]
                reduced_k = k - current_length // 2
                break

        prev_char = self.kthCharacter(reduced_k, operations)

        if operation_type == 0:
            return prev_char
        else:
            return 'a' if prev_char == 'z' else chr(ord(prev_char) + 1)
