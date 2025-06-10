// Solution for Maximum Difference Between Even and Odd Frequency I in CPP

class Solution {
public:
    int maxDifference(string s) {
        // Count frequency of each character (a-z)
        vector<int> charFreq(26, 0);
        for (char ch : s) {
            charFreq[ch - 'a']++;
        }
        
        // Track maximum odd frequency and minimum even frequency
        int maxOddFreq = 0;
        int minEvenFreq = INT_MAX;
        
        for (int i = 0; i < 26; i++) {
            if (charFreq[i] == 0) continue; // Skip characters not in string
            
            if (charFreq[i] % 2 == 0) {
                // Update minimum even frequency
                minEvenFreq = min(minEvenFreq, charFreq[i]);
            } else {
                // Update maximum odd frequency
                maxOddFreq = max(maxOddFreq, charFreq[i]);
            }
        }
        
        // Return difference: max odd frequency - min even frequency
        return maxOddFreq - minEvenFreq;
    }
};
