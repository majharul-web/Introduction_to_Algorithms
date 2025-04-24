#include <bits/stdc++.h>
using namespace std;

// input row,col and set grid,vis,move vector
int N, M;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> moveList = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// check is valid
bool isValid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < M;
}

// dfs function
void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + moveList[i].first;
        int cj = sj + moveList[i].second;

        if (isValid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.'))
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    // input 2d grid

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    // set visited array all value false
    memset(vis, false, sizeof(vis));

    // count component
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // if item is . and not visited
            if (grid[i][j] == '.')
            {
                if (!vis[i][j])
                {
                    count++;
                    dfs(i, j);
                }
            }
        }
    }

    // print finall result component count as apartment
    cout << count << endl;

    return 0;
}