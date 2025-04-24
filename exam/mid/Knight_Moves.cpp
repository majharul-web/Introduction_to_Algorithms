#include <bits/stdc++.h>
using namespace std;

int N, M;
bool vis[105][105];
int level[105][105];

vector<pair<int, int>> mooveList = {
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {2, 1}, {1, 2}, {-1, 2}};

// Check validity
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
    level[si][sj] = 0;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + mooveList[i].first;
            int cj = par_j + mooveList[i].second;

            if (isValid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    // Input test case,size and source,destination
    int T;
    cin >> T;

    while (T--)
    {
        cin >> N >> M;

        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        // bfs
        bfs(si, sj);
        cout << level[di][dj] << endl;
    }

    return 0;
}
