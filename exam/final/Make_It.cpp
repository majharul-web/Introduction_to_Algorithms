
#include <bits/stdc++.h>
using namespace std;

long long int in;

bool is_possible(long long int N)
{
    if (N > in)
        return false;

    if (N == in)
        return true;

    bool t1 = is_possible(N + 3);
    bool t2 = is_possible(N * 2);

    return t1 || t2;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> in;
        if (is_possible(1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}