// Solution for Robot Collisions in JAVA

class Solution {
    public List<Integer> survivedRobotsHealths(int[] pos, int[] health, String dir) {
        int n = pos.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) idx[i] = i;

        Arrays.sort(idx, (a, b) -> pos[a] - pos[b]);

        Stack<Integer> st = new Stack<>();

        for (int i : idx) {
            if (dir.charAt(i) == 'R') st.push(i);
            else {
                while (!st.isEmpty() && health[i] > 0) {
                    int j = st.pop();
                    if (health[j] > health[i]) {
                        health[j]--;
                        health[i] = 0;
                        st.push(j);
                    } else if (health[j] < health[i]) {
                        health[i]--;
                        health[j] = 0;
                    } else {
                        health[i] = health[j] = 0;
                    }
                }
            }
        }

        List<Integer> res = new ArrayList<>();
        for (int h : health) if (h > 0) res.add(h);
        return res;
    }
}
