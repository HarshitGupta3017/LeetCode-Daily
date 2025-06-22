// Solution for Divide a String Into Groups of Size k in CPP

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();

        // Traverse the string in steps of size k
        for (int i = 0; i < n; i += k) {
            // Calculate the actual substring size (might be less than k at the end)
            int len = min(k, n - i);

            // Extract substring of up to k characters starting from index i
            string group = s.substr(i, len);

            // If substring length is less than k, pad it with the fill character
            if (len < k) {
                group += string(k - len, fill);
            }

            result.push_back(group);
        }

        return result;
    }
};
