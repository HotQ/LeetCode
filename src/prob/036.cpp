class Solution
{
  public:
    bool exist(set<char> const &s, const char &c){
        if (s.find(c) == s.end())return false;
        else                     return true;
    }
    bool isValidSudoku(vector<vector<char>> &board) {
        set<char> row[9], col[9], box[9];
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j){
                if (board[i][j] == '.') continue;
                char &tmp = board[i][j];
                if (exist(row[i], tmp) || exist(col[j], tmp) || exist(box[i / 3 * 3 + j / 3], tmp)) return false;
                else {
                    row[i].insert(tmp);
                    col[j].insert(tmp);
                    box[i / 3 * 3 + j / 3].insert(tmp);
                }
            }
        return true;
    }
};
