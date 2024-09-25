class TrieNode {
public:
    int count;
    TrieNode* children[26];
    TrieNode() : count(0) {
        memset(children, 0, sizeof(children));
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const auto& word: words) {
            TrieNode* node = root;
            for (const auto& ch: word) {
                int i = ch - 'a';
                if (!node->children[i]) {
                    node->children[i] = new TrieNode();
                }
                node = node->children[i];
                node->count++;
            }
        }
        vector<int> res;
        for (const auto& word: words) {
            TrieNode* node = root;
            int score = 0;
            for (const auto& ch: word) {
                int i = ch - 'a';
                node = node->children[i];
                score += node->count;
            }
            res.push_back(score);
        }
        return res;
    }
};
