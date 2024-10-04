class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i = 0, j = skill.size() - 1;
        int sum = skill[i] + skill[j];
        long long res = 0;
        while (i < j) {
            if (skill[i] + skill[j] == sum) {
                res += (skill[i] * skill[j]);
                i++, j--;
            } else return -1;
        }
        return res;
    }
};
