class Solution {
public:
    int findPar(int u, vector<int>& parent) {
        if (parent[u] == u)
            return u;
        return parent[u] = findPar(parent[u], parent);
    }

    void join(int u, int v, vector<int>& par) {
        int paru = findPar(u, par);
        int parv = findPar(v, par);
        par[paru] = parv;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // dfs to ad count unvisited
        // better done with DSU
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<vector<int>> adj(n);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            join(v,u, parent);
        }

        int ans = 0;
        unordered_map<int, int> parents;

        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
ans++;
            }
            parents[findPar(parent[i], parent)]++;
        }
        // set of parents, then dijkstra on each, sub ans on an unreachable

        for (auto p : parents) {
            int node = p.first;
            int size = p.second;
            if (adj[node].size() != size - 1) {
                ans--;
                continue;
            }
            if (adj[node].size() == size - 1) {

                for (int nbr : adj[node]) {
                    if (adj[nbr].size() != size - 1) {
                        ans--;
                        break;
                    }
                }
            }
        }

        return (ans< 0) ? 0 : ans;
    }
};

// given an interger n,