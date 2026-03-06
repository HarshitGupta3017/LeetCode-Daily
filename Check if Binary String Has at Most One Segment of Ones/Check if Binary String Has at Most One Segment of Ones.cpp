// Solution for Check if Binary String Has at Most One Segment of Ones in CPP

class Solution {
public:
    bool checkOnesSegment(string s) {
        // Idea:
        // A binary string has more than one segment of '1's if it contains the pattern "01".
        // Why?
        // Example: 111011
        //            ^  ^
        //            |  |
        //        first segment ends at '0', and later another '1' starts
        // This creates a "01" transition (1 -> 0) followed by another '1', meaning
        // the ones are split into multiple segments.
        // As in constraints, s starts with 1 so after first segment we can check for '01'
        // If "01" never appears, then once the string becomes '0', it never goes
        // back to '1', meaning all '1's form a single contiguous segment.
        //
        // string::npos means the substring was NOT found.
        return s.find("01") == string::npos;
    }
};
