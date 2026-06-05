// Solution for Total Waviness of Numbers in Range II in CPP

class Solution {
public:
    using ll = long long;

    string s;   // digit string of the upper bound being processed
    int n;      // number of digits in s

    // dpN[pos][prevPrev][prev] = count of valid completions from position pos onward,
    // given that the two most recent non-leading digits were prevPrev and prev.
    ll dpN[16][10][10];

    // dpW[pos][prevPrev][prev] = total waviness contributed by all valid completions
    // from position pos onward, given the same two-digit context.
    ll dpW[16][10][10];

    // Returns {countOfNumbers, totalWaviness} for all ways to fill positions [curr..n-1],
    // given that the digit placed two steps ago was prevPrev and one step ago was prev.
    // prevPrev = -1 or prev = -1 means we don't have enough placed digits yet to judge a peak/valley.
    // isLimit: whether every digit placed so far matched the upper bound s exactly.
    // isLeadZero: whether every digit placed so far has been a leading zero (number hasn't started).
    pair<ll, ll> solve(int curr, int prevPrev, int prev, bool isLimit, bool isLeadZero) {
        if (curr == n)
            // We've placed all digits. This is one complete number with no remaining waviness to add.
            return {1, 0};

        // Only cache states where the digit choices are unconstrained (not tight against the bound)
        // and the number has actually started (no leading zeros), and we have a full two-digit context.
        // States that are still tight or still in leading-zero territory are too specific to reuse.
        if (!isLimit && !isLeadZero && prevPrev >= 0 && prev >= 0) {
            if (dpN[curr][prevPrev][prev] != -1 && dpW[curr][prevPrev][prev] != -1)
                return {dpN[curr][prevPrev][prev], dpW[curr][prevPrev][prev]};
        }

        ll totalCount    = 0;
        ll totalWaviness = 0;

        // If we're still tight against the upper bound, we can only go up to s[curr].
        // Otherwise any digit 0–9 is fair game.
        int digitLimit = isLimit ? (s[curr] - '0') : 9;

        for (int d = 0; d <= digitLimit; d++) {
            bool stillLeadZero = isLeadZero && (d == 0);

            // If d is a leading zero, the number hasn't started yet, so prevPrev stays
            // undefined. Otherwise, the window slides: the old prev becomes the new prevPrev.
            int newPrevPrev = prev;
            int newPrev     = stillLeadZero ? -1 : d;

            auto [remainCount, remainWaviness] = solve(
                curr + 1,
                newPrevPrev,
                newPrev,
                isLimit && (d == digitLimit),
                stillLeadZero
            );

            // Now that we know digit d will follow prev and prevPrev,
            // we can judge whether prev is a peak or valley.
            // We need all three digits to be real (no leading zeros, no missing context).
            if (!stillLeadZero && prevPrev >= 0 && prev >= 0) {
                bool isPeak   = (prevPrev < prev && prev > d);
                bool isValley = (prevPrev > prev && prev < d);

                if (isPeak || isValley) {
                    // prev is a peak/valley for every number that can be formed by
                    // the remaining digits, so its contribution scales with remainCount.
                    totalWaviness += remainCount;
                }
            }

            totalCount    += remainCount;
            totalWaviness += remainWaviness;
        }

        // Store in cache only when the result is reusable across different numbers
        // (i.e. not constrained by the upper bound and past leading zeros).
        if (!isLimit && !isLeadZero && prevPrev >= 0 && prev >= 0) {
            dpN[curr][prevPrev][prev] = totalCount;
            dpW[curr][prevPrev][prev] = totalWaviness;
        }

        return {totalCount, totalWaviness};
    }

    // Returns total waviness of all integers in [1, num].
    ll countUpTo(ll num) {
        // Numbers with fewer than 3 digits have no interior positions,
        // so they can never have a peak or valley — skip them entirely.
        if (num < 100)
            return 0;

        memset(dpN, -1, sizeof(dpN));
        memset(dpW, -1, sizeof(dpW));

        s = to_string(num);
        n = s.size();

        auto [totalCount, totalWaviness] = solve(0, -1, -1, true, true);

        return totalWaviness;
    }

    long long totalWaviness(long long num1, long long num2) {
        // Standard digit DP range trick: answer for [num1, num2] = f(num2) - f(num1 - 1).
        return countUpTo(num2) - countUpTo(num1 - 1);
    }
};
