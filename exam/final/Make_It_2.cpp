#include <bits/stdc++.h>
using namespace std;

long long int in;
int dp[1000005];

bool is_possible(long long int N)
{
    if (N > in)
        return false;
    if (N == in)
        return true;

    if (N >= 0 && N <= in && dp[N] != -1)
        return dp[N];

    bool t1 = is_possible(N + 3);
    bool t2 = is_possible(N * 2);

    dp[N] = t1 || t2;
    return dp[N];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> in;
        memset(dp, -1, sizeof(dp));

        if (is_possible(1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
