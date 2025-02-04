#include <bits/stdc++.h>
using namespace std;

void bfs(int src, int n, vector<vector<int>> &adj_list, vector<int> &parent, vector<int> &level)
{
    queue<int> q;
    vector<bool> vis(n + 1, false);

    q.push(src);
    vis[src] = true;
    level[src] = 1;
    parent[src] = -1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n + 1);
    vector<int> parent(n + 1, -1);
    vector<int> level(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs(1, n, adj_list, parent, level);

    if (parent[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << level[n] << endl;

    vector<int> path;
    int node = n;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());

    for (int x : path)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
