# Solution for Angle Between Hands of a Clock in PY

class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        
        # Minute hand: 6° per minute
        minuteAngle = minutes * 6.0

        # Hour hand: 30° per hour + 0.5° per minute (it creeps forward)
        # hour % 12 handles the case hour=12 (should act like 0)
        hourAngle = (hour % 12) * 30.0 + minutes * 0.5

        # Absolute difference between the two angles
        diff = abs(hourAngle - minuteAngle)

        # Clock angle has two measures (diff and 360-diff)
        # Return the smaller one
        return min(diff, 360.0 - diff)
