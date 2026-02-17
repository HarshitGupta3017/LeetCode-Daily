// Solution for Binary Watch in JAVA

class Solution {
    public List<String> readBinaryWatch(int turnedOn) {

        List<String> possibleTimes = new ArrayList<>();

        for (int hour = 0; hour <= 11; hour++) {
            for (int minute = 0; minute <= 59; minute++) {

                // Count total bits ON
                int totalBitsOn = Integer.bitCount(hour) + Integer.bitCount(minute);

                if (totalBitsOn == turnedOn) {

                    // Hour: no leading zero needed
                    String hourStr = String.valueOf(hour);

                    // Minute: must be 2 digits
                    String minuteStr = (minute < 10 ? "0" : "") + minute;

                    possibleTimes.add(hourStr + ":" + minuteStr);
                }
            }
        }

        return possibleTimes;
    }
}
