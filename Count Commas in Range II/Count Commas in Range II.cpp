// Solution for Count Commas in Range II in CPP

class Solution {
public:
    using ll = long long;

    long long countCommas(long long n) {
        // Numbers gain their first comma at 1,000 (4 digits → 1 comma),
        // their second at 1,000,000 (7 digits → 2 commas), and so on.
        // Every number in [threshold, n] contributes at least one comma
        // for the current threshold level — and since we iterate through
        // all threshold levels, each number ends up contributing exactly
        // one count per comma it contains in its formatted representation.
        ll totalCommas = 0;
        ll threshold = 1000;

        while (threshold <= n) {
            // All integers in [threshold, n] have at least one more comma
            // than integers just below threshold, so each contributes 1 here.
            totalCommas += (n - threshold + 1);
            threshold *= 1000;
        }

        return totalCommas;
    }
};
