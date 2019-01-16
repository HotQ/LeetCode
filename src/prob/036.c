bool isValidSudoku(char **board, int boardRowSize, int boardColSize){
    bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j){
            if (board[i][j] == '.')continue;
            int tmp = board[i][j] - '1';
            if  (row[i][tmp] ||col[j][tmp] ||box[i / 3 * 3 + j / 3][tmp]) return false;
            else row[i][tmp] = col[j][tmp] = box[i / 3 * 3 + j / 3][tmp] = true;
        }
    return true;
}
