// Solution for Minimum Number of People to Teach in JAVA

class Solution {
    public int minimumTeachings(int n, int[][] userLanguages, int[][] friendships) {
        Set<Integer> sad = new HashSet<>();
        for (int[] f : friendships) {
            int a = f[0]-1, b = f[1]-1;
            boolean canTalk = false;
            for (int lang : userLanguages[a]) {
                for (int l : userLanguages[b]) if (lang == l) { canTalk = true; break; }
                if (canTalk) break;
            }
            if (!canTalk) { sad.add(a); sad.add(b); }
        }
        int[] freq = new int[n+1];
        int maxF = 0;
        for (int u : sad) for (int l : userLanguages[u]) maxF = Math.max(maxF, ++freq[l]);
        return sad.size() - maxF;
    }
}
