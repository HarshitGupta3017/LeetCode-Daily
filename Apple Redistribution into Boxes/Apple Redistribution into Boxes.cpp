// Solution for Apple Redistribution into Boxes in CPP

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        int count = 0;
        for (int i = 0; i < capacity.size() && totalApples > 0; i++) {
            totalApples -= capacity[i];
            count++;
        }
        return count;
    }
};
