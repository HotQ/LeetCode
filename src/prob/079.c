bool exit_DFS(char** board, int boardRowSize, int boardColSize, char* word, int x, int y);
bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
	bool res = false;
	for (int i = 0; i < boardRowSize; ++i) 
		for (int j = 0; j < boardColSize; ++j) 
			if (board[i][j] == word[0]) 
				res = res || exit_DFS(board, boardRowSize, boardColSize, word, i, j);
	return res;
}

bool exit_DFS(char** board, int boardRowSize, int boardColSize, char* word, int x, int y) {
	char tmp = board[x][y];
    if (word[0] != tmp) return false;
    if (word[1] == '\0')return true;
    
	board[x][y] = '\0';
	
    ++word;
	bool res = false;
	if (x)                    res = res || exit_DFS(board, boardRowSize, boardColSize, word, x - 1, y);
	if (x + 1 < boardRowSize) res = res || exit_DFS(board, boardRowSize, boardColSize, word, x + 1, y);
	if (y)                    res = res || exit_DFS(board, boardRowSize, boardColSize, word, x, y - 1);
	if (y + 1 < boardColSize) res = res || exit_DFS(board, boardRowSize, boardColSize, word, x, y + 1);

	board[x][y] = tmp;
	return res;
}
