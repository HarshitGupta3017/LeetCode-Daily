# Solution for Rotate String in PY

class Solution:
    def rotateString(self, s, goal):
        return len(s) == len(goal) and goal in (s + s)
