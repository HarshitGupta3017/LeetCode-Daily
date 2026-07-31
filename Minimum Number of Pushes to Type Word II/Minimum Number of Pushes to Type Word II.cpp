// Solution for Minimum Number of Pushes to Type Word II in CPP

class Solution {
public:
    int minimumPushes(string word) {
        // Count how many times each letter appears, since a more frequent
        // letter should be assigned to a lower-cost slot to minimise total pushes.
        vector<int> freq(26, 0);
        for (char ch : word)
            freq[ch - 'a']++;

        // Sort frequencies descending so the most frequent letters are assigned first.
        // The first 8 letters (one per key) each cost 1 push,
        // the next 8 cost 2 pushes, the next 8 cost 3, and so on.
        sort(freq.begin(), freq.end(), greater<int>());

        int totalPushes = 0;
        for (int i = 0; i < 26; i++)
            totalPushes += freq[i] * (i / 8 + 1);

        return totalPushes;
    }
};
