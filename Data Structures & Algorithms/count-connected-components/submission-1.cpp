class Solution {
public:

void dfs(int node, vector<int>&vis, vector<vector<int>>&adjlist){
    vis[node]=1;
    for(auto nbh: adjlist[node]){
        if(!vis[nbh]){
            dfs(nbh, vis, adjlist);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>>adjlist(n);
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                adjlist[u].push_back(v);
                adjlist[v].push_back(u);
            }
            vector<int>vis(n,0);
            int components= 0;
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    components++;
                    dfs(i, vis, adjlist);
                }
            }
            return components;
    }          
};
