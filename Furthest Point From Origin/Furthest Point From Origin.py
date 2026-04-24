# Solution for Furthest Point From Origin in PY

class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        
        L = R = blank = 0
        
        for ch in moves:
            if (ch == 'L'):
                L += 1
            elif (ch == 'R'):
                R += 1
            else:
                blank += 1

        return abs(L - R) + blank
