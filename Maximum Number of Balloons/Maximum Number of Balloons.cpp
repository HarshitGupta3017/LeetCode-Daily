// Solution for Maximum Number of Balloons in CPP

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for (char ch : text)
            freq[ch - 'a']++;

        // "balloon" needs: 1 'b', 1 'a', 2 'l', 2 'o', 1 'n'.
        // The bottleneck letter determines how many full words we can form.
        // 'l' and 'o' each appear twice per word, so we halve their counts
        // before taking the minimum — otherwise we'd overcount by 2x.
        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};
