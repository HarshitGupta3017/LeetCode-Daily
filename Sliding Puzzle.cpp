class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};
        string target = "123450";
        string input = "";
        for (const auto& row: board) {
            for (const auto& num: row) {
                input += to_string(num);
            }
        }
        unordered_set<string> vis;
        queue<string> q;
        q.push(input);
        vis.insert(input);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if (curr == target) return level;
                int idx = curr.find('0');
                for (const auto& i: mp[idx]) {
                    string newcurr = curr;
                    swap(newcurr[i], newcurr[idx]);
                    if (vis.find(newcurr) == vis.end()) {
                        vis.insert(newcurr);
                        q.push(newcurr);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
