// Solution for Find Closest Person in CPP

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int person1diff = abs(z - x);
        int person2diff = abs(z - y);
        if (person1diff < person2diff) {
            return 1;
        } else if (person1diff > person2diff) {
            return 2;
        } 
        return 0;
    }
};
