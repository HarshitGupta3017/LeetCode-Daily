# Solution for Check if Binary String Has at Most One Segment of Ones in PY

class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return "01" not in s
