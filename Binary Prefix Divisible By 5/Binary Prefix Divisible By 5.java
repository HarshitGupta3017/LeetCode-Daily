// Solution for Binary Prefix Divisible By 5 in JAVA

class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> result = new ArrayList<>();  

        // 'prefixMod' will store the value of the current binary number % 5.
        // We never store the whole number because it gets huge.
        int prefixMod = 0;

        for (int bit : nums) {

            /*
                How binary expansion works:
                
                If we currently formed binary number = X,
                and next bit is b (0 or 1), the new number becomes:

                    newX = X * 2 + b

                Instead of storing X, we store (X % 5) because:
                (X * 2 + b) % 5 = ((X % 5) * 2 + b) % 5

                This is enough to check divisibility by 5.
            */

            // Update prefix modulo 5 by shifting left (multiply by 2) and adding current bit.
            prefixMod = ((prefixMod << 1) + bit) % 5;

            // If modulo becomes 0 → full number divisible by 5.
            result.add(prefixMod == 0);
        }

        return result;
    }
}
