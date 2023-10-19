#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> adj(N);
        for (const vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> count(N, 1);
        vector<int> res(N, 0);
        
        dfs1(0, -1, adj, count, res);
        dfs2(0, -1, adj, count, res, N);
        
        return res;
    }
    
    void dfs1(int node, int parent, const vector<vector<int>>& adj, vector<int>& count, vector<int>& res) {
        for (int child : adj[node]) {
            if (child == parent) continue;
            dfs1(child, node, adj, count, res);
            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
    }
    
    void dfs2(int node, int parent, const vector<vector<int>>& adj, vector<int>& count, vector<int>& res, int N) {
        for (int child : adj[node]) {
            if (child == parent) continue;
            res[child] = res[node] - count[child] + N - count[child];
            dfs2(child, node, adj, count, res, N);
        }
    }
};

int main() {
    Solution solution;
    int N = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};

    vector<int> result = solution.sumOfDistancesInTree(N, edges);

    cout << "Sum of Distances from each node to all other nodes:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}
