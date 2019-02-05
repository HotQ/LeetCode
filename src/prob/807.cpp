class Solution{
  public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid){
        int ans = 0;
        vector<int> horz(grid.size(),    0),
                    vert(grid[0].size(), 0);
        for (int i = 0; i < horz.size(); ++i)
            for (int j = 0; j < vert.size(); ++j){
                if (grid[i][j] > horz[i]) horz[i] = grid[i][j];
                if (grid[i][j] > vert[j]) vert[j] = grid[i][j];
            }
        for (int i = 0; i < horz.size(); ++i)
            for (int j = 0; j < vert.size(); ++j)
                if (grid[i][j] < horz[i] &&
                    grid[i][j] < vert[j])
                    ans += (horz[i] < vert[j] ? horz[i] : vert[j]) - grid[i][j];
        return ans;
    }
};
