class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp;
        for (const char& ch: s) mp[ch]++;
        priority_queue<pair<char, int>> pq;
        for (const auto& it: mp) pq.push({it.first, it.second});
        string res;
        while (!pq.empty()) {
            auto [ch, count] = pq.top();
            pq.pop();
            int limit = min(count, repeatLimit);
            res.append(limit, ch);
            count -= limit;
            if (count > 0) {
                if (pq.empty()) break;
                auto [nextch, nextcount] = pq.top();
                pq.pop();
                res.push_back(nextch);
                nextcount--;
                if (nextcount > 0) pq.push({nextch, nextcount});
                pq.push({ch, count});
            }
        }
        return res;
    }
};
