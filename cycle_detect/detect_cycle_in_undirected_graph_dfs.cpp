#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
int parent[105];

bool cycle;

void dfs(int src)
{
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (vis[child] && parent[src] != child)
        {
            cycle = true;
        }

        if (!vis[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    if (cycle)
    {
        cout << "Cycle detected!";
    }
    else
    {
        cout << "No cycle";
    }

    return 0;
}

/*

input:
6 5
0 1
1 2
2 3
3 0
4 5

output: Cycle detected!

6 4
0 1
1 2
2 3
4 5

output: No cycle

2 1
1 0
output: No cycle



*/
