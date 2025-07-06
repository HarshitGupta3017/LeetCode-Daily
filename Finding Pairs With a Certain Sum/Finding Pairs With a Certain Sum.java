// Solution for Finding Pairs With a Certain Sum in JAVA

class FindSumPairs {
    private int[] nums1, nums2;
    private Map<Integer, Integer> freqMap;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        this.freqMap = new HashMap<>();

        for (int num : nums2) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
    }

    public void add(int index, int val) {
        int oldVal = nums2[index];
        freqMap.put(oldVal, freqMap.get(oldVal) - 1);

        nums2[index] += val;
        int newVal = nums2[index];
        freqMap.put(newVal, freqMap.getOrDefault(newVal, 0) + 1);
    }

    public int count(int tot) {
        int totalPairs = 0;
        for (int num1 : nums1) {
            int required = tot - num1;
            totalPairs += freqMap.getOrDefault(required, 0);
        }
        return totalPairs;
    }
}
