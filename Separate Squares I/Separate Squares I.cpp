// Solution for Separate Squares I in CPP

class Solution {
public: 

    bool isBottomAreaEnough(vector<vector<int>>& squares, double mid_y, double totalArea) {

        double bottomArea = 0.0;
        for (const auto& square: squares) {
            double y = square[1];
            double l = square[2];

            double top_y = y + l;
            double bot_y = y;

            if (mid_y > top_y) {
                // full square below
                bottomArea += (l * l);
            } else if (mid_y > bot_y) {
                // partial square
                bottomArea += ((mid_y - y) * l);
            }
        }   

        /*
        We need to divide in a line such that both top and down areas are equal
        So if both will be equal then 
        Top Area = Total Area / 2
        Bottom Area = Total Area / 2
        So if we get Bottom Area and Total Area we can compare Top with that without actually
        finding Top Area
        if Bottom Area > Total Area or even if both are equal we need to shift downwards for 
        more smaller value
        */
        return bottomArea >= totalArea / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = DBL_MAX;
        double high = DBL_MIN;
        double totalArea = 0.0;

        for (const auto& square: squares) {
            double y = square[1];
            double l = square[2];

            totalArea += (l * l);
            low = min(low, y);
            high = max(high, y + l);
        }   

        double result_y = 0.0;

        /*  
        Answers within 10-5 of the actual answer will be accepted.
        This line means that even if our answer is 1e-5 away from actual answer it will be
        accepted, so instead of low <= high, for accurate precision we will check
        if difference of high and low is less than 1e-5, if yes then accepted 
        Also as there is precision we won't be shifting high and low with mid + 1 or -1
        instead assign only mid to them due to precision issues 
        */
        while (high - low > 1e-5) {
            double mid_y = low + (high - low) / 2.0;
            if (isBottomAreaEnough(squares, mid_y, totalArea)) {
                result_y = mid_y;
                high = mid_y;
            } else {
                low = mid_y;
            }
        }

        return result_y;
    }
};
