#include <bits/stdc++.h>
using namespace std;

long long int tetranacci(int N)
{
    vector<long long int> dp(65);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }

    return dp[N];
}

int main()
{
    int N;
    cin >> N;
    cout << tetranacci(N) << endl;
    return 0;
}
