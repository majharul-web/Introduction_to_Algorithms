#include <bits/stdc++.h>
using namespace std;

int dp[35];

int tetranacci(int N)
{
    if (N == 0)
        return 0;
    if (N == 1 || N == 2)
        return 1;
    if (N == 3)
        return 2;

    if (dp[N] != -1)
        return dp[N];

    dp[N] = tetranacci(N - 1) + tetranacci(N - 2) + tetranacci(N - 3) + tetranacci(N - 4);
    return dp[N];
}

int main()
{
    int N;
    cin >> N;

    memset(dp, -1, sizeof(dp));

    cout << tetranacci(N) << endl;
    return 0;
}
