// Solution for Divide a String Into Groups of Size k in JAVA

class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        int totalGroups = (n + k - 1) / k;
        String[] result = new String[totalGroups];

        for (int i = 0, index = 0; i < n; i += k, index++) {
            int end = Math.min(i + k, n);
            String group = s.substring(i, end);

            if (group.length() < k) {
                StringBuilder sb = new StringBuilder(group);
                for (int j = group.length(); j < k; j++) {
                    sb.append(fill);
                }
                group = sb.toString();
            }

            result[index] = group;
        }

        return result;
    }
}
