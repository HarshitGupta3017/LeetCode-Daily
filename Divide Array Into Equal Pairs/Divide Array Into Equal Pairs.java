// Solution for Divide Array Into Equal Pairs in JAVA

class Solution {
    public boolean divideArray(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int num: nums) mp.put(num, mp.getOrDefault(num, 0) + 1);
        for (Map.Entry<Integer, Integer> it: mp.entrySet()) {
            if (it.getValue() % 2 != 0) return false;
        }
        return true;
    }
}
