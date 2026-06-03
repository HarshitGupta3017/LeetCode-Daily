# Solution for Earliest Finish Time for Land and Water Rides II in PY

class Solution:
    def earliestFinishTime(self, landStartTime, landDuration,
                           waterStartTime, waterDuration):

        def solve(s1, d1, s2, d2):
            first_finish = min(s + d for s, d in zip(s1, d1))
            return min(max(first_finish, s) + d for s, d in zip(s2, d2))

        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        )
