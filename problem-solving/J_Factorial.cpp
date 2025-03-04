#include <bits/stdc++.h>
using namespace std;

long long int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}

int main()
{

    int N;
    cin >> N;
    cout << fact(N) << "\n";
    return 0;

    return 0;
}