# Solution for Solving Questions With Brainpower in PY

class Solution:

    def solve(self, i: int, q: List[List[int]], t: List[int], n: int) -> int:
        if i >= n:
            return 0
        if t[i] != -1: 
            return t[i]
        taken = q[i][0] + self.solve(i + q[i][1] + 1, q, t, n)
        not_taken = self.solve(i + 1, q, t, n)
        t[i] = max(taken, not_taken)
        return t[i]

    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        t = [-1] * (n + 1)
        return self.solve(0, questions, t, n)
