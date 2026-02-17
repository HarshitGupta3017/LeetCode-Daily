// Solution for Binary Watch in CPP

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {

        /*
            We will try every possible valid time:
            Hours   -> 0 to 11   (4 LEDs)
            Minutes -> 0 to 59   (6 LEDs)

            Total combinations:
            12 * 60 = 720  → very small
        */

        vector<string> possibleTimes;

        for (int hour = 0; hour <= 11; hour++) {

            for (int minute = 0; minute <= 59; minute++) {

                /*
                    Count how many bits are ON
                    in hour and minute combined.
                */
                int totalBitsOn = __builtin_popcount(hour) + __builtin_popcount(minute);

                /*
                    If number of LEDs ON matches turnedOn,
                    then this is a valid time.
                */
                if (totalBitsOn == turnedOn) {

                    /*
                        Hour:
                        - No leading zero allowed
                        - to_string(hour) handles it correctly
                    */
                    string hourStr = to_string(hour);

                    /*
                        Minute:
                        - Must always be 2 digits
                        - Add leading zero if < 10
                    */
                    string minuteStr = (minute < 10 ? "0" : "") + to_string(minute);

                    possibleTimes.push_back(hourStr + ":" + minuteStr);
                }
            }
        }

        return possibleTimes;
    }
};
