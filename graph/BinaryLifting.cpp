#include <bits/stdc++.h>
using namespace std;

/**
 * Computes LCA of two nodes in a tree in O(log N) time
 * Finds k^th ancestor of a node in a tree in O(log N) time
 * Precomputation takes O(N log N) time + O(N log N) memory
 * Tested on: https://judge.yosupo.jp/problem/lca
*/
class LCA {
public:
    int n, l, timer;
    vector<vector<int>> adj, up;
    vector <int> tin, tout;
    LCA(vector<vector<int>> _adj, int root = 0) : adj(_adj) {
        n = adj.size();
        l = ceil(log2(n)) + 1;
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(l));
        dfs(root, root, 0);
    }
    void dfs(int node, int prev, int d) {
        tin[node] = ++timer;
        up[node][0] = prev;
        for(int i = 1; i < l; i++) { up[node][i] = up[up[node][i - 1]][i - 1]; }
        for(auto next : adj[node]) { if(next != prev) dfs(next, node, d + 1); }
        tout[node] = ++timer;
    }
    bool is_ancestor(int x, int y) { return tin[x] <= tin[y] && tout[x] >= tout[y]; }
    int query(int u, int v) {
        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;
        for(int i = l - 1; i >= 0; i--) { if(!is_ancestor(up[u][i], v)) u = up[u][i]; }
        return up[u][0];
    }
    int jump(int x, int k) {
        for(int i = l - 1; i >= 0; i--) if((k>>i) & 1) x = up[x][i];
        return x;
    }
};