// Solution for Minimum Pair Removal to Sort Array I in JAVA

class Solution {

    private int minIdx(List<Integer> nums) {
        int minIndex = -1;
        int minSum = Integer.MAX_VALUE;

        for (int i = 0; i < nums.size() - 1; i++) {
            int sum = nums.get(i) + nums.get(i + 1);
            if (sum < minSum) {
                minSum = sum;
                minIndex = i;
            }
        }
        return minIndex;
    }

    private boolean isSorted(List<Integer> nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums.get(i) < nums.get(i - 1)) {
                return false;
            }
        }
        return true;
    }

    public int minimumPairRemoval(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }

        int operations = 0;

        while (!isSorted(list)) {
            int idx = minIdx(list);
            list.set(idx, list.get(idx) + list.get(idx + 1));
            list.remove(idx + 1);
            operations++;
        }

        return operations;
    }
}
