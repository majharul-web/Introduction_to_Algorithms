#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> parent[1005][1005];

vector<pair<int, int>> moveList = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int N, M;

// Chaeck validity
bool isValid(int i, int j)
{
    return (i >= 0 && i < N && j >= 0 && j < M);
}

// BFS function
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + moveList[i].first;
            int cj = par_j + moveList[i].second;

            if (isValid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
}

int main()
{
    // Input grid
    cin >> N >> M;

    int si, sj, di, dj;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    bfs(si, sj);

    // Change grid
    if (vis[di][dj])
    {
        int x = di, y = dj;
        while (grid[x][y] != 'R')
        {
            auto par = parent[x][y];
            x = par.first;
            y = par.second;
            if (grid[x][y] == 'R')
            {
                break;
            }
            else
            {
                grid[x][y] = 'X';
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
