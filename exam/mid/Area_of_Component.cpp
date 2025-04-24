#include <bits/stdc++.h>
using namespace std;

int N, M;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> moveList = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int componentSize;

// Check validity
bool isValid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < M;
}

// DFS function to count size of a component
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    componentSize++;

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

    memset(vis, false, sizeof(vis));

    int minSize = INT_MAX;
    bool isComp = false;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                isComp = true;
                componentSize = 0;
                dfs(i, j);
                minSize = min(minSize, componentSize);
            }
        }
    }

    // Print minimum size or -1 for no component
    cout << (isComp ? minSize : -1) << endl;

    return 0;
}
