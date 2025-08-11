// Solution for Range Product Queries of Powers in JAVA

class Solution {
    public int[] productQueries(int n, int[][] queries) {
        final int MOD = 100_00_00_007;

        List<Integer> powersOfTwo = new ArrayList<>();

        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if ((n & (1 << bitPosition)) != 0) {
                powersOfTwo.add(1 << bitPosition); 
            }
        }

        int q = queries.length;
        int[] queryResults = new int[q];

        for (int i = 0; i < q; i++) {
            int leftIndex = queries[i][0];  
            int rightIndex = queries[i][1]; 
            long product = 1;     

            for (int idx = leftIndex; idx <= rightIndex; idx++) {
                product = (product * powersOfTwo.get(idx)) % MOD;
            }

            queryResults[i] = (int) product; 
        }

        return queryResults;
    }
}
