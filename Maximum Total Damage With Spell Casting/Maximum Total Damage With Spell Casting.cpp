// Solution for Maximum Total Damage With Spell Casting in CPP

class Solution {
public:
    using ll = long long;

    // Recursive function to compute the maximum damage starting from index 'i'
    ll computeMaxDamage(vector<ll>& uniqueDamages, int i, vector<ll>& memo, unordered_map<int, ll>& damageCountMap) {
        // Base case: no more spells to consider
        if (i >= uniqueDamages.size()) return 0;

        // Return memoized result if already computed
        if (memo[i] != -1) return memo[i];

        // Option 1: Skip the current spell damage
        ll skipCurrent = computeMaxDamage(uniqueDamages, i + 1, memo, damageCountMap);

        // Option 2: Take the current spell damage and skip incompatible ones
        // Find next valid index — where damage > currentDamage + 2
        int nextValidIndex = upper_bound(uniqueDamages.begin() + i + 1, uniqueDamages.end(), uniqueDamages[i] + 2) - uniqueDamages.begin();

        // Calculate total damage if we choose this spell damage
        ll takeCurrent = uniqueDamages[i] * damageCountMap[uniqueDamages[i]] 
                         + computeMaxDamage(uniqueDamages, nextValidIndex, memo, damageCountMap);

        // Store and return the maximum of both options
        return memo[i] = max(skipCurrent, takeCurrent);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, ll> damageCountMap;

        // Count frequency of each unique damage value
        for (const auto& damage : power) {
            damageCountMap[damage]++;
        }

        // Extract unique damage values and sort them
        vector<ll> uniqueDamages;
        for (const auto& entry : damageCountMap) {
            uniqueDamages.push_back(entry.first);
        }
        sort(uniqueDamages.begin(), uniqueDamages.end());

        int n = uniqueDamages.size();
        vector<ll> memo(n, -1); // Memoization array for DP

        // Compute and return the maximum possible total damage
        return computeMaxDamage(uniqueDamages, 0, memo, damageCountMap);
    }
};
