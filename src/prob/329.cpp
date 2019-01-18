#include <iostream>
#include <vector>
#include <map>
class Solution{
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix){
        if (matrix.size() == 0)return 0;
        multimap<int, pair<int, int>> ordMap;
        int row = matrix.size(),
            col = matrix[0].size(), max = 1,
            **status = new int *[row];
        for (int i = 0; i < row; ++i){
            status[i] = new int[col];
            for (int j = 0; j < col; ++j){
                ordMap.insert(pair<int, pair<int, int>>(matrix[i][j], {i, j}));
                status[i][j] = 1;
            }
        }
        for (auto rit = ordMap.rbegin(); rit != ordMap.rend(); ++rit){
            int x = rit->second.first,
                y = rit->second.second,
                crt = rit->first;
            if (x           && matrix[x - 1][y] > crt && status[x][y] < status[x - 1][y] + 1) status[x][y] = status[x - 1][y] + 1;
            if (x + 1 < row && matrix[x + 1][y] > crt && status[x][y] < status[x + 1][y] + 1) status[x][y] = status[x + 1][y] + 1;
            if (y           && matrix[x][y - 1] > crt && status[x][y] < status[x][y - 1] + 1) status[x][y] = status[x][y - 1] + 1;
            if (y + 1 < col && matrix[x][y + 1] > crt && status[x][y] < status[x][y + 1] + 1) status[x][y] = status[x][y + 1] + 1;
            if (max < status[x][y])
                max = status[x][y];
        }
        return max;
    }
};
