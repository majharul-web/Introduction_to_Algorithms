#include <bits/stdc++.h>
using namespace std;

int n, m;

char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        cout << par_i << " " << par_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (isValid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    memset(vis, false, sizeof(vis));

    bfs(si, sj);

    return 0;
}

/*
input:
3 4
. . . .
. . . .
. . . .
1 2

output:
1 2
0 2
0 1
1 1
2 1
2 0
1 0
0 0
2 2
2 3
1 3
0 3

*/

/*

complexity:

O(V+E)  E is constant=4

Final complexity: n * m (Row * Col)



*/
