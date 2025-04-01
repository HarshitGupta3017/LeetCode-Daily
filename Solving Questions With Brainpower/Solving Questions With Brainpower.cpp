// Solution for Solving Questions With Brainpower in CPP

class Solution {
public:

    long long solve(int i, vector<vector<int>>& q, vector<long long>& t, int n) {
        if (i >= n) return 0;
        if (t[i] != -1) return t[i];
        long long taken = q[i][0] + solve(i + q[i][1] + 1, q, t, n);
        long long not_taken = solve(i + 1, q, t, n);
        return t[i] = max(taken, not_taken);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> t(n + 1, -1);
        return solve(0, questions, t, n);
    }
};
