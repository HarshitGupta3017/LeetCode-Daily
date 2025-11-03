// Solution for Minimum Time to Make Rope Colorful in CPP

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        
        // 'time' will store the total minimum time required to make the rope colorful
        int time = 0;
        
        // 'prevMax' keeps track of the maximum removal time in the current group of same-colored balloons
        int prevMax = 0;
        
        // Traverse through all balloons
        for (int i = 0; i < n; i++) {
            
            // If the current balloon color is different from the previous one,
            // reset 'prevMax' since a new color group starts here
            if (i > 0 && colors[i] != colors[i - 1]) 
                prevMax = 0;
            
            // 'curr' represents the removal time for the current balloon
            int curr = neededTime[i];
            
            // If there’s a color conflict (same color group),
            // remove the one with smaller time and keep the larger one
            time += min(prevMax, curr);
            
            // Update 'prevMax' to keep the most expensive balloon for the current color group
            prevMax = max(prevMax, curr);
        }
        
        // Return the total minimum time needed to make the rope colorful
        return time;
    }
};
