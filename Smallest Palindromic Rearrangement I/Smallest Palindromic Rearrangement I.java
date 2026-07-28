// Solution for Smallest Palindromic Rearrangement I in JAVA

class Solution {
    public String smallestPalindrome(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length, half = n / 2;

        Arrays.sort(arr, 0, half);

        for (int i = 0; i < half; i++)
            arr[n - 1 - i] = arr[i];

        return new String(arr);
    }
}
