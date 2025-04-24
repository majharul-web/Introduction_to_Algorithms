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

        if (isValid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'B'))
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    // input 2d grid and source,distanation

    cin >> N >> M;
    int si, sj, di, dj;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    dfs(si, sj);

    // check visited and print result
    if (vis[di][dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
