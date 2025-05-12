// Solution for Finding 3-Digit Even Numbers in JAVA

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        ArrayList<Integer> res = new ArrayList<>();
        int[] freq = new int[10];
        for (int digit: digits) {
            freq[digit]++;
        }
        for (int i = 1; i <= 9; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;
            for (int j = 0; j <= 9; j++) {
                if (freq[j] == 0) continue;
                freq[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (freq[k] == 0) continue;
                    freq[k]--;
                    int num = i * 100 + j * 10 + k;
                    res.add(num);
                    freq[k]++;
                }
                freq[j]++;
            }
            freq[i]++;
        }
        int[] ans = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            ans[i] = res.get(i);
        }
        return ans;
    }
}
