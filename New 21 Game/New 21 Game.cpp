// Solution for New 21 Game in CPP

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        // dp[i] = probability ki exact score "i" aaye
        vector<double> dp(n + 1, 0.0);  
        dp[0] = 1.0;  // Base case: score 0 hone ki prob = 1 (game start yahin se hoga)

        // Ye sum rakhega last maxPts scores ka jo abhi tak valid hain
        double probWindowSum = (k == 0) ? 0 : 1;  

        // Har possible score ke liye calculate karna hai
        for (int score = 1; score <= n; score++) {
            
            // Probability banegi window sum / maxPts
            dp[score] = probWindowSum / maxPts;

            // Agar score < k hai to isko future ke liye window me include karo
            if (score < k) 
                probWindowSum += dp[score];

            // Agar window size maxPts se bada ho gaya to purana element hatao
            if (score - maxPts >= 0 && score - maxPts < k)
                probWindowSum -= dp[score - maxPts];
        }

        // Answer hoga probability ki score k se n ke beech aayi ho
        return accumulate(begin(dp) + k, end(dp), 0.0);
    }
};
