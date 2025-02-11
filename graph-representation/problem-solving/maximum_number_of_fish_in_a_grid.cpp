#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    bool vis[505][505]; // Increased size for larger grids

    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

    int fishCount;

    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;

        fishCount += grid[si][sj];

        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] > 0)
            {
                dfs(ci, cj, grid);
            }
        }
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        int maxFish = 0;
        n = grid.size();
        m = grid[0].size();
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] > 0)
                {
                    fishCount = 0;
                    dfs(i, j, grid);
                    maxFish = max(maxFish, fishCount);
                }
            }
        }

        return maxFish;
    }
};

int main()
{
    vector<vector<int>> grid1 = {{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}};
    vector<vector<int>> grid2 = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}};

    Solution obj;
    cout << obj.findMaxFish(grid1) << endl; // Output: 7
    cout << obj.findMaxFish(grid2) << endl; // Output: 1

    return 0;
}
