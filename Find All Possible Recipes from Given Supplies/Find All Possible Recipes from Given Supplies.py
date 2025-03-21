# Solution for Find All Possible Recipes from Given Supplies in PY

class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        st = set(supplies)
        res = []
        found = True
        while found:
            found = False
            for i in range(len(recipes)):
                if recipes[i] in st:
                    continue
                canMake = True
                if all(ingr in st for ingr in ingredients[i]):
                    st.add(recipes[i])
                    res.append(recipes[i])
                    found = True
        return res
