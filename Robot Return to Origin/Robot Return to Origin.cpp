// Solution for Robot Return to Origin in CPP

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (const auto& ch: moves) {
            if (ch == 'U') y++;
            else if (ch == 'D') y--;
            else if (ch == 'L') x--;
            else x++;
        }
        return (x == 0 && y == 0);
    }
};
