// Solution for Lexicographically Minimum String After Removing Stars in CPP

class Solution {
public:
    // Pair alias: stores character and its index
    using CharIndex = pair<char, int>;

    // Custom comparator for the min-heap
    struct Compare {
        // Smaller character comes first; if equal, earlier index comes first
        bool operator()(const CharIndex& a, const CharIndex& b) {
            return a.first != b.first ? a.first > b.first : a.second < b.second;
        }
    };

    string clearStars(string s) {
        // Min-heap to find the smallest non-'*' character before each '*'
        priority_queue<CharIndex, vector<CharIndex>, Compare> minHeap;

        // Step 1: Simulate the process
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                minHeap.push({s[i], i});  // Store character with its index
            } else {
                // When '*' is found, remove smallest non-'*' character to its left
                if (!minHeap.empty()) {
                    int idxToRemove = minHeap.top().second;
                    minHeap.pop();
                    s[idxToRemove] = '*';  // Mark the removed character as '*'
                }
            }
        }

        // Step 2: Build the result without '*' characters
        string result = "";
        for (char ch : s) {
            if (ch != '*') result += ch;
        }

        return result;
    }
};
