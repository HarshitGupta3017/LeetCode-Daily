// Solution for Compare Version Numbers in JAVA

import java.util.StringTokenizer;

class Solution {

    // Helper method: split version string into integer parts
    private List<Integer> splitVersion(String version) {
        StringTokenizer tokenizer = new StringTokenizer(version, ".");
        List<Integer> versionParts = new ArrayList<>();

        // Convert each part of version into integer
        while (tokenizer.hasMoreTokens()) {
            versionParts.add(Integer.parseInt(tokenizer.nextToken()));
        }
        return versionParts;
    }

    public int compareVersion(String version1, String version2) {
        // Split both version strings into integer lists
        List<Integer> version1Parts = splitVersion(version1);
        List<Integer> version2Parts = splitVersion(version2);

        int length1 = version1Parts.size();    // Number of parts in version1
        int length2 = version2Parts.size();    // Number of parts in version2
        int maxLength = Math.max(length1, length2);  // Total iterations required

        // Compare each version part one by one
        for (int index = 0; index < maxLength; index++) {
            // If part is missing in a version, treat it as 0
            int part1 = (index < length1 ? version1Parts.get(index) : 0);
            int part2 = (index < length2 ? version2Parts.get(index) : 0);

            // Direct comparison
            if (part1 < part2) return -1;   // version1 < version2
            if (part1 > part2) return 1;    // version1 > version2
            // If equal, continue checking next part
        }

        // All parts equal
        return 0;
    }
}
