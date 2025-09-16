// Solution for Replace Non-Coprime Numbers in Array in JAVA

class Solution {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> finalArray = new ArrayList<>();

        for (int num : nums) {
            // Merge until coprime
            while (!finalArray.isEmpty()) {
                int lastNum = finalArray.get(finalArray.size() - 1);
                int currentGCD = gcd(lastNum, num);

                if (currentGCD == 1) break;

                finalArray.remove(finalArray.size() - 1);
                long lcmValue = 1L * lastNum / currentGCD * num;
                num = (int) lcmValue;
            }
            finalArray.add(num);
        }

        return finalArray;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
