# Solution for Range Product Queries of Powers in PY

class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        MOD = 10**9+7

        powers_of_two = [1 << bit_position for bit_position in range(32) if n & (1 << bit_position)]

        queryResults = []

        for leftIdx, rightIdx in queries: 
            product = prod(powers_of_two[idx] for idx in range(leftIdx, rightIdx + 1)) % MOD
            
            queryResults.append(product) 

        return queryResults
