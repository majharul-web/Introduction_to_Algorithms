#include <bits/stdc++.h>
using namespace std;

int N, M;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> moveList = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Check validity
bool isValid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < M;
}

// DFS function
void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + moveList[i].first;
        int cj = sj + moveList[i].second;

        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    // Input grid
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Input source and destination
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    // If start or end cell is valid
    if (grid[si][sj] == '-' || grid[di][dj] == '-')
    {
        cout << "NO" << endl;
    }
    else
    {
        // Print valid output
        memset(vis, false, sizeof(vis));
        dfs(si, sj);
        cout << (vis[di][dj] ? "YES" : "NO") << endl;
    }

    return 0;
}
