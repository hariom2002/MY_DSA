class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
        
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int minTime = 0;
        int time = 0;
        
        int dellRow[4] = {-1, +1, 0, 0};
        int dellCol[4] = {0, 0, -1, +1};
        while(!q.empty()){
            
            auto itr = q.front();
            q.pop();
            int row = itr.first.first;
            int col = itr.first.second;
            time = itr.second;
            
            for(int i=0;i<4;i++){
                
                int nRow = row + dellRow[i];
                int nCol = col + dellCol[i];
                
               if(nRow < grid.size() && nRow >= 0 && nCol < grid[0].size() && nCol >= 0 && vis[nRow][nCol]!=2 &&  grid[nRow][nCol] == 1){
                vis[nRow][nCol] = 2;
                q.push({{nRow, nCol}, time+1});
                }
            }
            
        }
        
        minTime = time;
        
        for(auto it1: vis){
            for(auto it2: it1){
                if(it2 == 1)
                    return -1;
            }
        }
        return time;
        
    }
};