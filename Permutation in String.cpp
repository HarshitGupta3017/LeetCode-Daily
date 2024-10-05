class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        vector<int> v1(26, 0), v2(26, 0);
        for (int i = 0; i < n1; i++) {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        int match = 0;
        for (int i = 0; i < 26; i++) {
            if (v1[i] == v2[i]) match++;
        }
        for (int i = n1; i < n2; i++) {
            if (match == 26) return true;
            int curr = s2[i] - 'a';
            v2[curr]++;
            if (v2[curr] == v1[curr]) match++;
            else if (v2[curr] == v1[curr] + 1) match--;
            int prev = s2[i - n1] - 'a';
            v2[prev]--;
            if (v2[prev] == v1[prev]) match++;
            if (v2[prev] == v1[prev] - 1) match--;
        }
        return match == 26;
    }
};
