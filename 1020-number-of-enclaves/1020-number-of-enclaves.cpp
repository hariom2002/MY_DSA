class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         vector<vector<int>> dup(grid);
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(dup[i][j] == 1){
                        dfs(i, j, grid, dup);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == -1)
                    grid[i][j] = 0;
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
    
     void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dup){
        
        grid[row][col] = -1;
        
        int newRow[4] = {-1, 0, +1, 0};
        int newCol[4] = {0, -1, 0, +1};
        
        for(int i=0;i<4;i++){
            
            int r = row + newRow[i];
            int c = col + newCol[i];
            
            if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && dup[r][c] == 1 && grid[r][c] != -1)dfs(r, c, grid, dup);
            
        } 
    }
};