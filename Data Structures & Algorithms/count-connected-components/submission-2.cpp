class Solution {
public:

    void bfs(int start, vector<int>& vis, vector<vector<int>>& adjList) {

        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto nbh : adjList[node]) {

                if(!vis[nbh]) {
                    vis[nbh] = 1;
                    q.push(nbh);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(n);

        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int components = 0;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {
                components++;
                bfs(i, vis, adjList);
            }
        }

        return components;
    }
};