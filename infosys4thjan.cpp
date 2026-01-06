#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent,
        vector<vector<int>> &adj,
        vector<int> &values,
        int k,
        int &count) {

    int sum = values[node - 1]; 

    for (int neigh : adj[node]) {
        if (neigh != parent) {
            sum += dfs(neigh, node, adj, values, k, count);
        }
    }

    if (sum % k == 0) {
        count++;
    }

    return sum;
}

int luckypath(int N, int k,
             vector<vector<int>> edges,
             vector<int> values) {

    vector<vector<int>> adj(N + 1);

    
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
    }

    int count = 0;

    // Root = 1 
    dfs(1, -1, adj, values, k, count);

    return count;
}
