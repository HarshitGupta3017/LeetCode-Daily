// Solution for Number of People Aware of a Secret in CPP

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Recursive helper function:
    // Returns the number of new people who learn the secret on 'day'
    int countNewPeople(int day, int delay, int forget, vector<int> &memo) {
        if (day == 1) return 1; // Base case: Day 1, exactly 1 person knows the secret

        if (memo[day] != -1) return memo[day]; // Already computed → return memoized value

        int ways = 0;

        // Loop through all possible "starting days" d such that
        // someone who learned on 'd' can pass the secret to 'day'
        for (int d = day - forget + 1; d <= day - delay; d++) {
            if (d > 0) { 
                ways = (ways + countNewPeople(d, delay, forget, memo)) % MOD;
            }
        }

        return memo[day] = ways;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> memo(n + 1, -1); // Memoization table for days
        int total = 0;

        // At the end of day n, only people who haven’t forgotten remain.
        // That means they learned the secret in the window [n - forget + 1, n].
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                total = (total + countNewPeople(day, delay, forget, memo)) % MOD;
            }
        }

        return total;
    }
};
