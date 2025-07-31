// Solution for Bitwise ORs of Subarrays in JAVA

class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> prevOrs = new HashSet<>();
        Set<Integer> currOrs = new HashSet<>();
        Set<Integer> distinctOrs = new HashSet<>();

        for (int i = 0; i < arr.length; i++) {
            currOrs.add(arr[i]);
            distinctOrs.add(arr[i]);

            for (int prevVal : prevOrs) {
                int newOr = prevVal | arr[i];
                currOrs.add(newOr);
                distinctOrs.add(newOr);
            }

            prevOrs = new HashSet<>(currOrs);
            currOrs.clear();
        }

        return distinctOrs.size();
    }
}
