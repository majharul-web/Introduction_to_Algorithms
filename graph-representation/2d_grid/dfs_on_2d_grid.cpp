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

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (isValid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
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

    dfs(si, sj);

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
