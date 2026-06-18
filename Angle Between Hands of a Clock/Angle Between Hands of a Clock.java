// Solution for Angle Between Hands of a Clock in JAVA

class Solution {
    public double angleClock(int hour, int minutes) {
        
        // Minute hand: 6° per minute
        double minuteAngle = minutes * 6.0;

        // Hour hand: 30° per hour + 0.5° per minute (it creeps forward)
        // hour % 12 handles the case hour=12 (should act like 0)
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;

        // Absolute difference between the two angles
        double diff = Math.abs(hourAngle - minuteAngle);

        // Clock angle has two measures (diff and 360-diff)
        // Return the smaller one
        return Math.min(diff, 360.0 - diff);
    }
}
