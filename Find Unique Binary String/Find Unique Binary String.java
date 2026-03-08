// Solution for Find Unique Binary String in JAVA

class Solution {
    public String findDifferentBinaryString(String[] nums) {

        /*
         We construct a binary string guaranteed
         to differ from every string in nums.

         Cantor's Diagonal Argument:
         Flip the i-th bit of nums[i].
        */

        int n = nums.length;
        StringBuilder differentString = new StringBuilder();

        for (int i = 0; i < n; i++) {

            // Look at diagonal bit nums[i][i] and flip it
            if (nums[i].charAt(i) == '0')
                differentString.append('1');
            else
                differentString.append('0');
        }

        return differentString.toString();
    }
}
