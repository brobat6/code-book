#include <bits/stdc++.h>
using namespace std;

/**
 * Finds strongly connected components in a directed graph. If
 * vertices u, v belong to the same component, we can reach u 
 * from v and vice-versa. 
 * Modify process() as needed.
 * Source : KACTL, cp-algorithms.  
*/
class SCC {
public:
    vector<vector<int>> adj, adj_rev;
    vector<bool> used;
    vector<int> order, comp;

    SCC(vector<vector<int>> &_adj) {
        adj = _adj;
        int n = adj.size();
        adj_rev.resize(n);
        for(int i = 0; i < n; i++) {
            for(auto j : adj[i]) {
                adj_rev[j].push_back(i);
            }
        }   
        used.assign(n, false);
        for(int i = 0; i < n; i++) {
            if(!used[i]) dfs1(i);
        }
        used.assign(n, false);
        reverse(order.begin(), order.end());
        for(auto v : order) {
            if(!used[v]) {
                dfs2(v);

                process();

                comp.clear();
            }
        }
    }

    void process() {
        // Process next SCC.
    }

    void dfs1(int node) {
        used[node] = true;
        for(auto next : adj[node]) {
            if(!used[next]) dfs1(next);
        }
        order.push_back(node);
    }

    void dfs2(int node) {
        used[node] = true;
        comp.push_back(node);
        for(auto next : adj_rev[node]) {
            if(!used[next]) dfs2(next);
        }
    }
};
