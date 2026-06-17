class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    void unionBySize(int u, int v) {
        int ul_pu = findUPar(u);  // ultimate parent of u
        int ul_pv = findUPar(v);  // ultimate parent of v
        if (ul_pu == ul_pv) return; // already in the same component

        // attach smaller tree under larger tree
        if (size[ul_pu] < size[ul_pv]) {
            parent[ul_pu] = ul_pv;
            size[ul_pv] += size[ul_pu];
        } else {
            parent[ul_pv] = ul_pu;
            size[ul_pu] += size[ul_pv];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n+1);// 1 for safer side
        for(auto &it : edges){
            int  u = it[0];
            int v = it[1];

           if (ds.findUPar(u) == ds.findUPar(v)) {
                return {u, v};
            }

            ds.unionBySize(u, v);
        }

        return {};
    }
};