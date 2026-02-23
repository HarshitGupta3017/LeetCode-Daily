// Solution for Check If a String Contains All Binary Codes of Size K in JAVA

class Solution {
    public boolean hasAllCodes(String s, int k) {

        int totalCodesNeeded = 1 << k;
        Set<String> seen = new HashSet<>();

        for (int i = k; i <= s.length(); i++) {

            String sub = s.substring(i - k, i);

            if (!seen.contains(sub)) {
                seen.add(sub);
                totalCodesNeeded--;
            }

            if (totalCodesNeeded == 0)
                return true;
        }

        return false;
    }
}
