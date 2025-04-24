// Solution for Count Complete Subarrays in an Array in JAVA

class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> st = new HashSet<>();
        for (int num : nums) st.add(num);
        int n = nums.length, i = 0, j = 0, res = 0, unique_ch = st.size();
        Map<Integer, Integer> mp = new HashMap<>();
        while (j < n) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            while (mp.size() == unique_ch) {
                res += n - j;
                mp.put(nums[i], mp.get(nums[i]) - 1);
                if (mp.get(nums[i]) == 0) mp.remove(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
}
