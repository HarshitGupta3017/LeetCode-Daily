// Solution for Partition Labels in JAVA

class Solution {
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        int[] mp = new int[26];
        for (int i = 0; i < n; i++) {
            mp[s.charAt(i) - 'a'] = i;
        }
        int i = 0, start = 0, end = 0;
        List<Integer> result = new ArrayList<>();
        while (i < n) {
            end = Math.max(end, mp[s.charAt(i) - 'a']);
            if (i == end) {
                result.add(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        return result;
    }
}
