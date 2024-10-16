class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        string res = "";
        while (!pq.empty()) {
            auto [currcount, currchar] = pq.top();
            pq.pop();
            if (res.size() >= 2 && res[res.size() - 1] == currchar && res[res.size() - 2] == currchar) {
                if (pq.empty()) break;
                auto [nextcount, nextchar] = pq.top();
                pq.pop();
                res.push_back(nextchar);
                nextcount--;
                if (nextcount > 0) pq.push({nextcount, nextchar});
            } else {
                res.push_back(currchar);
                currcount--;
            }
            if (currcount > 0) pq.push({currcount, currchar});
        }
        return res;
    }
};
