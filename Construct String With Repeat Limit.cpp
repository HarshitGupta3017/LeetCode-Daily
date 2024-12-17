class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // simple ques we can store characters and freq in max heap 
        // and then iterate over heap and append characters of size repeatlimit in result
        // if still the freq of that char is high then skip it and add next one
        unordered_map<char, int> freq;
        for (const auto& ch: s) freq[ch]++;
        priority_queue<pair<char, int>> pq;
        for (const auto& it: freq) pq.push({it.first, it.second});
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
