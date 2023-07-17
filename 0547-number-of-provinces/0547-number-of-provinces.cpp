class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> arrLst[v+1];
        
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    arrLst[i+1].push_back(j+1);
                    arrLst[j+1].push_back(i+1);
                }
                    
            }
        }
        
        int res = 0;   
        vector<int> vis(v+1,0);
        
        for(int i=1;i<=v;i++){
            if(!vis[i]){
                // cout<<"visited "<<i<<": "<<vis[i]<<endl;
                 res++;
                queue<int> q;
                vis[i] = 1;
                q.push(i);
                
                while(q.size()){
                    int node = q.front();
                    q.pop();
                    
                    for(auto it:arrLst[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        return res;
    }
};