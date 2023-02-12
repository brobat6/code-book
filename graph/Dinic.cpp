#include <bits/stdc++.h>
using namespace std;

struct FlowEdge {
    int from, to;
    long long cap, flow = 0;
    FlowEdge(int from, int to, long long cap) : from(from), to(to), cap(cap) {}
};

/**
 * Dinic's Maximum Flow Algorithm. Runs in O(V^2 * E) time for general 
 * graphs (theoretically, but much faster in practice, for graphs with 
 * E >> V it acts more like O(V^(2/3) * E)). Runs in O(sqrt(E) * E) for 
 * graphs with unit capacity edges, and O(sqrt(V) * E) for bipartite graphs.
 * For bipartite matching or vertex cover, use BipartiteMatching class instead.
*/ 
class Dinic {
public:
    const long long FLOW_INF = 1E18;
    vector<FlowEdge> edges; // Edge List of the flow graph
    vector<vector<int>> adj; // Contains pointers to the edge list
    int n; // Number of vertices in the graph
    int m = 0; // Number of edges in the graph (Multiplied by 2, becuase we store both forward and backward edges).
    int s; // source
    int t; // sink
    vector <int> level; // the level graph, contains level of every node in current iteration
    vector <int> ptr; // optimisation to prevent backtracking from dead ends
    queue <int> q; // for BFS
 
    Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
 
    void add_edge(int from, int to, long long cap) {
        edges.emplace_back(from, to, cap);
        edges.emplace_back(to, from, 0);
        adj[from].push_back(m);
        adj[to].push_back(m + 1);
        m += 2;
    }
 
    bool bfs() {
        // To get the current level graph
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int id : adj[curr]) {
                if(edges[id].cap - edges[id].flow < 1) continue;
                if(level[edges[id].to] != -1) continue;
                level[edges[id].to] = level[curr] + 1;
                q.push(edges[id].to);
            }
        }
        return level[t] != -1;
    }
 
    long long dfs(int node, long long pushed) {
        // To find a blocking flow in the current level graph
        if(pushed == 0) return 0;
        if(node == t) return pushed;
        for(int& cid = ptr[node]; cid < (int)adj[node].size(); cid++) {
            int id = adj[node][cid];
            int nx = edges[id].to;
            if(level[node] + 1 != level[nx] || edges[id].cap - edges[id].flow < 1) continue;
            long long tr = dfs(nx, min(pushed, edges[id].cap - edges[id].flow));
            if(tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
 
    long long flow() {
        // Find the maximum flow
        long long f = 0;
        while(true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if(!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(long long pushed = dfs(s, FLOW_INF)) {
                f += pushed;
            }
        }
        return f;
    }

    /**
     * From https://usaco.guide/adv/min-cut?lang=cpp.
     * Edges (a, b) connecting vertices that are reachable from the
     * sourcer (lev[a] != -1) to vertices that aren't (lev[b] == -1) 
     * are part of the minimum cut. 
    */
    vector<bool> min_cut() {
        vector <bool> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = (level[i] != -1);
        }
        return res;
    }
};