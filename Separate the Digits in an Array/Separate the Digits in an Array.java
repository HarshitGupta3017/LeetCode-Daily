// Solution for Separate the Digits in an Array in JAVA

class Solution {
    public int[] separateDigits(int[] nums) {

        List<Integer> digits = new ArrayList<>();

        // Process each number
        for (int num : nums) {

            // Convert number to string
            String str = String.valueOf(num);

            // Extract digits
            for (char ch : str.toCharArray()) {
                digits.add(ch - '0');
            }
        }

        // Convert List<Integer> -> int[]
        int[] result = new int[digits.size()];

        for (int i = 0; i < digits.size(); i++) {
            result[i] = digits.get(i);
        }

        return result;
    }
}
