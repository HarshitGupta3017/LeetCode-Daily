// Solution for Find All Possible Recipes from Given Supplies in CPP

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<string> res;
        bool found = true;
        while (found) {
            found = false;
            for (int i = 0; i < recipes.size(); i++) {
                if (st.count(recipes[i])) continue;
                bool canMake = true;
                for (const string& ingr: ingredients[i]) {
                    if (st.count(ingr) == 0) {
                        canMake = false;
                        break;
                    }
                }
                if (canMake) {
                    st.insert(recipes[i]);
                    res.push_back(recipes[i]);
                    found = true;
                }
            }
        }
        return res;
    }
};
