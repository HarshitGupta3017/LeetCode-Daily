// Solution for Find All Possible Recipes from Given Supplies in JAVA

class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Set<String> st = new HashSet<>(Arrays.asList(supplies));
        List<String> res = new ArrayList<>();
        boolean found = true;
        while (found) {
            found = false;
            for (int i = 0; i < recipes.length; i++) {
                if (st.contains(recipes[i])) continue;
                boolean canMake = true;
                for (String ingr: ingredients.get(i)) {
                    if (!st.contains(ingr)) {
                        canMake = false;
                        break;
                    }
                }
                if (canMake) {
                    st.add(recipes[i]);
                    res.add(recipes[i]);
                    found = true;
                }
            }
        }
        return res;
    }
}
