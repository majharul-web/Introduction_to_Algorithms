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
        int op_1 = val[i] + knapSack(i - 1, max_weight - weight[i]);
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
    int T;
    cin >> T;

    while (T--)
    {
        int N, max_weight;
        cin >> N >> max_weight;

        for (int i = 0; i < N; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> val[i];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= max_weight; j++)
            {
                dp[i][j] = -1;
            }
        }

        int result = knapSack(N - 1, max_weight);
        cout << result << endl;
    }

    return 0;
}
