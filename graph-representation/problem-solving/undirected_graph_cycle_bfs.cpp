#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool vis[100005];
    int parent[100005];
    bool cycle;

    void bfs(int src, vector<vector<int>> &adj_list)
    {
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            int par = q.front();
            q.pop();

            for (int child : adj_list[par])
            {
                if (vis[child] && parent[par] != child)
                {
                    cycle = true;
                }
                if (!vis[child])
                {
                    q.push(child);
                    vis[child] = true;
                    parent[child] = par;
                }
            }
        }
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        int V = adj.size();
        memset(vis, false, sizeof(vis));
        memset(parent, -1, sizeof(parent));
        cycle = false;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bfs(i, adj);
            }
        }

        return cycle;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        bool ans = obj.isCycle(adj);
        cout << (ans ? "1\n" : "0\n");
    }
    return 0;
}
