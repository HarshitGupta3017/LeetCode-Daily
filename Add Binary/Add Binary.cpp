// Solution for Add Binary in CPP

class Solution {
public:
    string addBinary(string a, string b) {

        /*
            Start from the last characters
            (least significant bits).
        */
        int indexA = a.length() - 1;
        int indexB = b.length() - 1;

        string result = "";

        int carry = 0;  // carry from previous addition

        /*
            Continue while:
            - digits remain in a OR
            - digits remain in b OR
            - there is a carry left
        */
        while (indexA >= 0 || indexB >= 0) {

            int currentSum = carry;

            // Add bit from string a if available
            if (indexA >= 0) {
                currentSum += a[indexA] - '0';
                indexA--;
            }

            // Add bit from string b if available
            if (indexB >= 0) {
                currentSum += b[indexB] - '0';
                indexB--;
            }

            /*
                Binary addition logic:

                sum  result  carry
                 0     0       0
                 1     1       0
                 2     0       1
                 3     1       1
            */

            result.push_back((currentSum % 2) + '0');
            carry = currentSum / 2;
        }

        // If carry remains after loop
        if (carry > 0) {
            result.push_back('1');
        }

        /*
            Result was built in reverse order
            (LSB → MSB), so reverse it.
        */
        reverse(result.begin(), result.end());

        return result;
    }
};
