// Solution for Maximize Active Section with Trade I in CPP

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Count active sections upfront — a trade never changes the total number
        // of 1s and 0s globally, but it can convert a 0-block into 1s by
        // sacrificing a neighbouring 1-block. The net gain is the size of the
        // absorbed 0-block minus the sacrificed 1-block, but since we're looking
        // at adjacent inactive blocks, the gain equals the larger 0-block's size
        // minus the smaller one's size... actually simpler: we just want the
        // maximum (left_zero_block + right_zero_block) added to the fixed 1-count.
        int totalActive = count(s.begin(), s.end(), '1');

        // Extract the lengths of all contiguous '0' blocks.
        // The augmented '1's at both ends (per the problem note) ensure that
        // every '0' block is surrounded by '1's — so any '0' block is a valid
        // target for the "fill zeros" half of the trade, and any adjacent pair
        // of '0' blocks (separated by a '1' block) can be combined via one trade.
        vector<int> zeroBlockLengths;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') i++;
                zeroBlockLengths.push_back(i - start);
            } else {
                i++;
            }
        }

        // A single trade lets us convert one '1'-block (between two '0'-blocks)
        // to all '0's, then merge those three segments and convert the combined
        // '0'-block to all '1's. The net effect on active count is:
        // gain = left_zero_block_size + right_zero_block_size
        // (the '1'-block in between is lost, but the two '0'-blocks become '1's).
        // We want the adjacent pair of '0'-blocks with the maximum combined size.
        int maxGain = 0;
        for (int j = 1; j < (int)zeroBlockLengths.size(); j++)
            maxGain = max(maxGain, zeroBlockLengths[j] + zeroBlockLengths[j - 1]);

        return totalActive + maxGain;
    }
};
