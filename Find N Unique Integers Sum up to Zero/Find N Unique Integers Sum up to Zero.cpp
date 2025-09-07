// Solution for Find N Unique Integers Sum up to Zero in CPP

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        
        // We want n unique integers that sum to 0.
        // Idea:
        //   - Pair numbers symmetrically: (-x, +x)
        //   - If n is odd, also include 0 in the middle
        
        for (int num = -(n / 2); num <= (n / 2); num++) {
            // If n is even, skip 0 (otherwise sum won't stay zero-balanced)
            if (num == 0 && n % 2 == 0) continue;
            
            result.push_back(num);
        }
        
        return result;
    }
};
