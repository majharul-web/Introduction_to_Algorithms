#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

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
            }
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
    memset(level, -1, sizeof(level));

    int src, dest;
    cin >> src >> dest;

    bfs(src);

    cout << level[dest] << endl;

    return 0;
}

/*
input:

5 4
1 2
1 3
2 4
3 5
1 4


output:2


input:
5 3
1 2
2 3
4 5
1 4

output:-1


 */