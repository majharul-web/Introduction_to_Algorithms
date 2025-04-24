#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
pair<int, int> parent[105][105];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // Right -> Left -> Up -> Down
int n, m;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && (grid[i][j] == '.' || grid[i][j] == 'D'));
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        auto [par_i, par_j] = q.front();
        q.pop();

        for (auto [di, dj] : d)
        { // Move in specified order
            int ci = par_i + di;
            int cj = par_j + dj;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};

                if (grid[ci][cj] == 'D')
                    return; // Stop BFS when 'D' is reached
            }
        }
    }
}

void markPath(int di, int dj, int si, int sj)
{
    int x = di, y = dj;
    while (grid[x][y] != 'R')
    {
        auto [px, py] = parent[x][y];
        if (grid[px][py] == 'R')
            break; // Stop before overwriting 'R'
        grid[px][py] = 'X';
        x = px, y = py;
    }
}

int main()
{
    cin >> n >> m;

    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
                si = i, sj = j;
            if (grid[i][j] == 'D')
                di = i, dj = j;
        }
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    bfs(si, sj);

    if (vis[di][dj])
    { // If path found, mark it
        markPath(di, dj, si, sj);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
