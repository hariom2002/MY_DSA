class Solution {
public:
    int res = 0;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        
        vector<int> arrLst[v];
        
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    arrLst[i].push_back(j);
                    arrLst[j].push_back(i);
                }
                    
            }
        }
        vector<bool> vis (v, false);
        for(int i = 0;i<v;i++){
            if(!vis[i]){
                res++;
                dfs(i,vis, arrLst);
                
            }
        }
        return res;
    }
    void dfs(int node,vector<bool> &vis, vector<int> graph[]){
        
        vis[node]= true;
        for(auto it: graph[node]){
            if(!vis[it]){
                dfs(it,vis, graph); 
            }
        }
    }
};