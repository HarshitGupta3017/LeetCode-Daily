// Solution for Smallest Divisible Digit Product II in CPP

class Solution {
public:
    using ll = long long;

    // Given a remaining factor `required` and a fixed number of digit slots,
    // greedily fill the slots with the largest possible digits (9 down to 2)
    // that divide `required`, then pad with 1s on the left.
    // The result is the lexicographically smallest suffix that covers `required`
    // because we place the largest divisors last (reversed at the end).
    string buildSuffix(ll required, int slots) {
        string suffix;

        // Absorb as many factors as possible using digits 9..2 (largest first
        // so we use fewer digits and leave room for 1-padding on the left).
        for (int digit = 9; digit >= 2; digit--) {
            while (required % digit == 0) {
                suffix.push_back('0' + digit);
                required /= digit;
            }
        }

        // If required > 1 after trying all digits 2-9, the remaining factor
        // cannot be expressed as a product of single digits — signal failure
        // by returning a string that is too long to fit in `slots`.
        if (required != 1) {
            suffix.push_back('X'); // sentinel: forces length check to fail
        }

        // Pad with 1s to reach the required slot count (1s don't affect the product).
        while ((int)suffix.size() < slots)
            suffix.push_back('1');

        // Digits were appended largest-first; reverse so the smallest digits
        // come first, giving the lexicographically smallest arrangement.
        reverse(suffix.begin(), suffix.end());
        return suffix;
    }

    string smallestNumber(string num, ll t) {
        int n = num.size();

        // t's prime factors must all be among {2, 3, 5, 7} — the only primes
        // that appear as single digits. Any other prime factor (11, 13, ...) can
        // never be covered by a product of single non-zero digits.
        ll remaining = t;
        for (int prime : {2, 3, 5, 7}) {
            while (remaining % prime == 0)
                remaining /= prime;
        }
        if (remaining != 1) return "-1";

        // remainingFactor[i] = what factor of t is still needed after multiplying
        // the first i digits of num into the product.
        // We track the unfulfilled portion of t as we consume digits of num.
        vector<ll> remainingFactor(n + 1, t);
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';

            // A zero digit means num itself is not zero-free — stop prefix here.
            if (digit == 0) break;

            remainingFactor[i + 1] = remainingFactor[i] / gcd(remainingFactor[i], (ll)digit);
        }

        // If the full number num already satisfies t, return it directly.
        if (remainingFactor[n] == 1) return num;

        // Find how far we can safely take digits from num unchanged.
        // We stop at the first zero (since zero-free is required) or the last digit.
        int firstZeroIdx = num.find('0');
        int searchUpTo = (firstZeroIdx != (int)string::npos) ? firstZeroIdx : n - 1;

        // Try incrementing each position from the boundary down to 0.
        // For each position i, we've fixed num[0..i-1] and we try replacing
        // num[i] with a larger digit, then filling num[i+1..n-1] optimally.
        for (int i = searchUpTo; i >= 0; i--) {
            ll neededFactor = remainingFactor[i];
            int freeSlotsAfter = n - 1 - i;

            // Try each digit larger than num[i] at position i.
            for (int digit = (num[i] - '0') + 1; digit <= 9; digit++) {
                ll factorAfterDigit = neededFactor / gcd(neededFactor, (ll)digit);
                string suffix = buildSuffix(factorAfterDigit, freeSlotsAfter);

                // buildSuffix returns a string longer than freeSlotsAfter if the
                // factor cannot be covered — skip this digit in that case.
                if ((int)suffix.size() == freeSlotsAfter)
                    return num.substr(0, i) + (char)('0' + digit) + suffix;
            }
        }

        // No valid number of the same length exists — use one extra digit.
        // e.g. num = "99", t = 2^15: we need more digits than n provides.
        return buildSuffix(t, n + 1);
    }
};
