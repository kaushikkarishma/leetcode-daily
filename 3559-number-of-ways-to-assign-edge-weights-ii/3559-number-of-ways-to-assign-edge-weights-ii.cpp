class Solution {
private:
    int n;
    int LOG;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<vector<int>> up;
    vector<long long> pow2;
    const int MOD = 1e9 + 7;

    void dfs(int node, int p, int d) {
        depth[node] = d;
        up[node][0] = p;
        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }
        for (int child : adj[node]) {
            if (child != p) {
                dfs(child, node, d + 1);
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        for (int i = LOG - 1; i >= 0; i--) {
            if (u != -1 && depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        
        adj.assign(n + 1, vector<int>());
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(1, -1, 0);

        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int lca = getLCA(u, v);
            int pathLength = depth[u] + depth[v] - 2 * depth[lca];

            long long ways = pow2[pathLength - 1];
            answer.push_back(ways);
        }

        return answer;
    }
};