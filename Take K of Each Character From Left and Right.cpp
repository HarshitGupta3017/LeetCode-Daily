class Solution {
public:
    int takeCharacters(string s, int k) {
        // another sliding window question 
        // in this instead of finding the elements to be rmeoved, keep track of elements to keep 
        // then at last we will subtract that from total length
        int n = s.size();
        int a_count = count(s.begin(), s.end(), 'a');
        int b_count = count(s.begin(), s.end(), 'b');
        int c_count = n - a_count - b_count;
        if (a_count < k || b_count < k || c_count < k) return -1;
        int i = 0, keep = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'a') a_count--;
            else if (s[j] == 'b') b_count--;
            else c_count--;
            while (i <= j && (a_count < k || b_count < k || c_count < k)) {
                // need to shrink window from left now
                if (s[i] == 'a') a_count++;
                else if (s[i] == 'b') b_count++;
                else c_count++;
                i++;
            }
            keep = max(keep, j - i + 1);
        }
        return n - keep;
    }
};
