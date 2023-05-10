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
        while(!q.empty()){
            
            auto itr = q.front();
            q.pop();
            int row = itr.first.first;
            int col = itr.first.second;
            time = itr.second;
            
            if(row+1 < grid.size() && vis[row+1][col]!=2 && grid[row+1][col] == 1){
                vis[row+1][col] = 2;
                q.push({{row+1, col}, time+1});
            }
            if(row-1 >= 0  && vis[row-1][col]!=2 &&  grid[row-1][col] == 1){
                vis[row-1][col] = 2;
                q.push({{row-1, col}, time+1});
            }
            if(col+1 < grid[0].size()  && vis[row][col+1]!=2 && grid[row][col+1] == 1){
                vis[row][col+1] = 2;
                q.push({{row, col+1}, time+1});
                
            }
            if(col-1 >= 0  && vis[row][col-1]!=2 && grid[row][col-1] == 1){
                vis[row][col-1] = 2;
                q.push({{row, col-1}, time+1});
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