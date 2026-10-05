class Solution {
public:
    int n, m;
    vector<vector<char>> grid;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int balance) {
        if (i >= n || j >= m)
            return false;

        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;


        if (i == n - 1 && j == m - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        return dp[i][j][balance] =
            solve(i + 1, j, balance) ||
            solve(i, j + 1, balance);
    }

    bool hasValidPath(vector<vector<char>>& g) {
        grid = g;
        n = grid.size();
        m = grid[0].size();

        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(')
            return false;

        dp.assign(n, vector<vector<int>>(m,
                  vector<int>(n + m + 1, -1)));

        return solve(0, 0, 0);
    }
};