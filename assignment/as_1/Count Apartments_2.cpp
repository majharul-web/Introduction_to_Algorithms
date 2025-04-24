#include <bits/stdc++.h>
using namespace std;

// input row,col and set grid,vis,move vector,totalApartment,apartmentCount
int N, M;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> moveList = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<int> totalApartment;
int apartmentCount;

// check is valid
bool isValid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < M;
}

// dfs function
void dfs(int si, int sj)
{
    vis[si][sj] = true;

    apartmentCount++;

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

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // if item is . and not visited
            if (grid[i][j] == '.')
            {
                if (!vis[i][j])
                {
                    apartmentCount = 0;
                    dfs(i, j);
                    totalApartment.push_back(apartmentCount);
                }
            }
        }
    }

    // print finall result as rooms
    if (totalApartment.empty())
    {
        cout << 0;
    }
    else
    {
        sort(totalApartment.begin(), totalApartment.end());
        for (int apCount : totalApartment)
        {
            cout << apCount << " ";
        }
    }

    return 0;
}
