# Solution for Earliest Finish Time for Land and Water Rides I in PY

class Solution:
    def earliestFinishTime(self, landStartTime, landDuration,
                           waterStartTime, waterDuration):
        ans = float('inf')

        for i in range(len(landStartTime)):
            land_end = landStartTime[i] + landDuration[i]

            for j in range(len(waterStartTime)):
                water_end = waterStartTime[j] + waterDuration[j]

                ans = min(
                    ans,
                    max(land_end, waterStartTime[j]) + waterDuration[j],
                    max(water_end, landStartTime[i]) + landDuration[i]
                )

        return ans
