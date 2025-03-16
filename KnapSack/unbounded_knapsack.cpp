#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];

int knapSack(int i, int max_weight)
{
    if (i < 0 || max_weight <= 0)
    {
        return 0;
    }

    if (dp[i][max_weight] != -1)
    {
        return dp[i][max_weight];
    }

    if (weight[i] <= max_weight)
    {
        int op_1 = val[i] + knapSack(i, max_weight - weight[i]);
        int op_2 = knapSack(i - 1, max_weight);
        dp[i][max_weight] = max(op_1, op_2);
        return dp[i][max_weight];
    }
    else
    {
        dp[i][max_weight] = knapSack(i - 1, max_weight);
        return dp[i][max_weight];
    }
}

int main()
{
    int n, max_wight;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cin >> max_wight;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= max_wight; j++)
        {
            dp[i][j] = -1;
        }
    }

    int result = knapSack(n - 1, max_wight);
    cout << result << endl;

    return 0;
}

/*
input:
3
5 3 2
4 2 3
6

output:
9


Complexity: O (N*W)
N = item
W = max_weight

*/
