// Solution for Closest Equal Element Queries in JAVA

class Solution {
    public List<Integer> solveQueries(int[] nums, int[] queries) {
        int n = nums.length;

        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }

        List<Integer> ans = new ArrayList<>();

        for (int idx : queries) {
            List<Integer> list = map.get(nums[idx]);

            if (list.size() == 1) {
                ans.add(-1);
                continue;
            }

            int pos = Collections.binarySearch(list, idx);
            int size = list.size();

            int prev = list.get((pos - 1 + size) % size);
            int next = list.get((pos + 1) % size);

            int d1 = Math.abs(prev - idx);
            int d2 = Math.abs(next - idx);

            ans.add(Math.min(Math.min(d1, d2), Math.min(n - d1, n - d2)));
        }

        return ans;
    }
}
