// Solution for Number of Paths with Max Score in CPP

class Solution {

    int n;
    int MOD = 1e9 + 7;

    // memo[i][j] = {bestScore, numberOfPathsAchievingBestScore} from cell (i,j) to 'E'.
    // Sentinel {-1, -1} means the cell hasn't been computed yet.
    vector<vector<pair<int,int>>> memo;

    int digitAt(char ch) {
        // 'S' is the starting cell and contributes no coins.
        // Numeric characters contribute their face value.
        return ch != 'S' ? ch - '0' : 0;
    }

    bool inBounds(int i, int j, vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }

    pair<int,int> solve(int i, int j, vector<string>& board) {
        // 'E' is the destination — no more coins to collect, and this is one complete path.
        if (board[i][j] == 'E') return {0, 1};

        // 'X' is an obstacle — should never be called on this, but guard anyway.
        if (board[i][j] == 'X') return {0, 0};

        if (memo[i][j] != make_pair(-1, -1)) return memo[i][j];

        // Try all three moves: up, left, diagonal up-left.
        // For each direction, we get the best score reachable from the neighbor.
        // If that neighbor has at least one valid path to 'E', we add the current
        // cell's coin value on top — the current cell's digit is collected when
        // we step onto it, so it counts for every path passing through here.
        int upScore = 0,   upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;

        if (inBounds(i - 1, j, board)) {
            auto [score, paths] = solve(i - 1, j, board);
            upPaths = paths;
            // Only add the current cell's digit if there is at least one reachable path,
            // otherwise we'd be counting coins for a dead-end route.
            upScore = (paths > 0) ? score + digitAt(board[i][j]) : 0;
        }
        if (inBounds(i, j - 1, board)) {
            auto [score, paths] = solve(i, j - 1, board);
            leftPaths = paths;
            leftScore = (paths > 0) ? score + digitAt(board[i][j]) : 0;
        }
        if (inBounds(i - 1, j - 1, board)) {
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagPaths = paths;
            diagScore = (paths > 0) ? score + digitAt(board[i][j]) : 0;
        }

        // Determine the best score among the three directions.
        // All directions achieving that best score contribute their path counts.
        int bestScore = max({upScore, leftScore, diagScore});
        int bestPaths = 0;

        // Accumulate path counts only from directions that match the best score
        // AND actually reach the destination (paths > 0 guard prevents dead ends
        // from contributing their zero-score to a legitimate bestScore of 0).
        if (upScore   == bestScore && upPaths   > 0) bestPaths = (bestPaths + upPaths)   % MOD;
        if (leftScore == bestScore && leftPaths > 0) bestPaths = (bestPaths + leftPaths) % MOD;
        if (diagScore == bestScore && diagPaths > 0) bestPaths = (bestPaths + diagPaths) % MOD;

        // If no direction leads anywhere, bestScore is meaningless — return {0, 0}.
        if (bestPaths == 0) bestScore = 0;

        memo[i][j] = {bestScore, bestPaths};
        return memo[i][j];
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        memo.assign(n, vector<pair<int,int>>(n, {-1, -1}));

        auto [score, paths] = solve(n - 1, n - 1, board);
        return {score, paths};
    }
};
