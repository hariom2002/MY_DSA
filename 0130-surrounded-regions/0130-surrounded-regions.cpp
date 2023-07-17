class Solution {
public:

    void solve(vector<vector<char>>& board) {
        
        vector<vector<char>> dup(board);
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(dup[i][j] == 'O'){
                        dfs(i, j, board, dup);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
        // return board;
        
    }
    
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<char>> &dup){
        
        board[row][col] = 'T';
        
        int newRow[4] = {-1, 0, +1, 0};
        int newCol[4] = {0, -1, 0, +1};
        
        for(int i=0;i<4;i++){
            
            int r = row + newRow[i];
            int c = col + newCol[i];
            
            if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && dup[r][c] == 'O' && board[r][c] != 'T')
            {
                dfs(r, c, board, dup);
                // dup[r][c] = 'O';
            }
        } 
    }
};