// Solution for Jump Game VII in CPP

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int totalLength = s.size();

        // reachable[i] = 1 means index i can be reached
        vector<int> reachable(totalLength, 0);

        // Starting index is always reachable
        reachable[0] = 1;

        // This variable stores how many reachable indices
        // currently exist inside the valid jump window
        //
        // For every index j,
        // valid previous positions are:
        // [j - maxJump, j - minJump]
        //
        // If at least one index inside this range
        // is reachable, then j can also become reachable.
        int reachableCountInsideWindow = 0;

        for (int currentIndex = 1; currentIndex < totalLength; currentIndex++) {

            // Add the new index entering the valid jump window
            //
            // currentIndex - minJump becomes reachable
            // candidate for currentIndex
            if (currentIndex - minJump >= 0) {

                reachableCountInsideWindow += reachable[currentIndex - minJump];
            }

            // Remove the index that is no longer inside
            // the valid jump window
            //
            // currentIndex - maxJump - 1 is now too far
            // to jump from
            if (currentIndex - maxJump - 1 >= 0) {

                reachableCountInsideWindow -= reachable[currentIndex - maxJump - 1];
            }

            // Current index becomes reachable if:
            //
            // 1. There exists at least one reachable index
            //    inside the allowed jump range
            //
            // 2. Current position contains '0'
            //    because we cannot land on '1'
            if (reachableCountInsideWindow > 0 && s[currentIndex] == '0') {

                reachable[currentIndex] = 1;
            }
        }

        // Return whether last index is reachable
        return reachable[totalLength - 1];
    }
};
