# Solution for Using a Robot to Print the Lexicographically Smallest String in PY

class Solution:
    def robotWithString(self, s: str) -> str:
        n = len(s)

        # Step 1: Compute the minimum character to the right (including self) for each index
        minRight = [''] * n
        minRight[-1] = s[-1]

        for i in range(n - 2, -1, -1):
            minRight[i] = min(s[i], minRight[i + 1])

        robotBuffer = []  # Acts like a stack t held by the robot
        paper = []        # Final written string

        for i in range(n):
            robotBuffer.append(s[i])  # Operation 1: move from s to t

            # Determine smallest character that remains in s
            smallestRemaining = minRight[i + 1] if i + 1 < n else s[i]

            # Operation 2: move from t to paper if top of t <= smallestRemaining
            while robotBuffer and robotBuffer[-1] <= smallestRemaining:
                paper.append(robotBuffer.pop())

        # Move any remaining characters from t to paper
        while robotBuffer:
            paper.append(robotBuffer.pop())

        return ''.join(paper)
