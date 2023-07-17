class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> dup(n, vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dup[i][j] = image[i][j];
            }
        }
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int src_clr = image[sr][sc];
        
        int newRow[4] = {-1, 0, +1, 0};
        int newCol[4] = {0, -1, 0, +1};
        
        image[sr][sc] = color;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            
            for(int i=0;i<4;i++){
                               
               int r = row + newRow[i];
               int c = col + newCol[i];
                
                if(r>=0 && r <n && c>=0 && c<m && dup[r][c] == src_clr && dup[r][c] != -1){
                    image[r][c] = color;
                    dup[r][c] = -1;
                    q.push({r, c});
                }
                
            }
        }
        return image;
    }
};