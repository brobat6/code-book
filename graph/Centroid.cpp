#include <bits/stdc++.h>
using namespace std;

/**
 * Performs centroid decomposition of the tree and constructs
 * a new tree with O(log N) depth.
 * Takes O(N log N) time. 
*/
class Centroid {
public:
    int n;
    vector<vector<int>> adj; // original tree
    vector<int> p; // new tree, represented by parent array
    vector<bool> vis;
    vector <int> sz; // size of subtree, will keep changing while finding centroid decomposition

    Centroid(vector<vector<int>> _adj) {
        adj = _adj;
        n = adj.size();
        p.assign(n, -1);
        vis.assign(n, false);
        sz.resize(n);
        init_centroid(0, -1);
    }

    int find_size(int node, int prev) {
        sz[node] = 1;
        for(auto next : adj[node]) {
            if(next != prev && !vis[next]) {
                sz[node] += find_size(next, node);
            }
        }
        return sz[node];
    }

    int find_centroid(int node, int prev, int n) {
        // n --> size of the subtree we are solving for
        for(auto next : adj[node]) {
            if(next != prev && !vis[next] && sz[next] > n/2) {
                return find_centroid(next, node, n);
            }   
        }
        return node;
    }

    void process(int node) {
        // Process node here.
    }

    void init_centroid(int node, int prev) {
        find_size(node, prev);
        int c = find_centroid(node, node, sz[node]);
        process(c);
        p[c] = prev;
        vis[c] = true;
        for(auto next : adj[c]) {
            if(!vis[next]) init_centroid(next, c);
        }
    }
};