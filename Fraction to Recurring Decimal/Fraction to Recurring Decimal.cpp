// Solution for Fraction to Recurring Decimal in CPP

class Solution {
public:

    using ll = long long;  // Alias for long long to avoid overflow issues

    string fractionToDecimal(int numerator, int denominator) {
        // Case 1: If numerator is 0, result is always "0"
        if (numerator == 0) return "0";

        string result;

        // Case 2: Handle negative result → add "-" sign if one is negative
        if ((ll)numerator * (ll)denominator < 0) result += "-";

        // Work with absolute values to simplify logic
        ll absNumerator = labs(numerator);
        ll absDenominator = labs(denominator);

        // Step 1: Compute the integer part (before decimal point)
        ll intDiv = absNumerator / absDenominator;
        result += to_string(intDiv);

        // Step 2: Compute the remainder after integer division
        ll remain = absNumerator % absDenominator;

        // If no remainder → it's an exact division, return result
        if (remain == 0) return result;

        // Step 3: Otherwise, fractional part exists → add decimal point
        result += ".";

        // Map to store remainder → index in result string
        // Used to detect repeating decimals
        unordered_map<int, int> mp;

        // Step 4: Simulate long division until remainder becomes 0
        while (remain != 0) {
            // If this remainder has been seen before → repeating cycle detected
            if (mp.count(remain)) {
                // Insert "(" at the position where repeat started
                result.insert(mp[remain], "(");
                // Append ")" at the end
                result += ")";
                break;
            }

            // Store current remainder's index (start of repeating block if seen again)
            mp[remain] = result.length();

            // Bring down a zero (long division step)
            remain *= 10;

            // Compute next digit of quotient
            ll intDiv = remain / absDenominator;
            result += to_string(intDiv);

            // Update remainder
            remain %= absDenominator;
        }

        return result;
    }
};
