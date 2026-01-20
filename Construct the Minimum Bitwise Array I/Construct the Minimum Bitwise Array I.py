# Solution for Construct the Minimum Bitwise Array I in PY

class Solution:
    def minBitwiseArray(self, nums):

        answer = []

        for target in nums:

            # Special case: 2 is impossible
            if target == 2:
                answer.append(-1)
                continue

            found = False

            # Find first zero bit
            for bit in range(1, 32):

                if target & (1 << bit):
                    continue

                # Flip previous bit
                candidate = target ^ (1 << (bit - 1))
                answer.append(candidate)
                found = True
                break

            if not found:
                answer.append(-1)

        return answer
