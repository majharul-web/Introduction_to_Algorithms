#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> edg_list;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edg_list.push_back({a, b});
    }

    for (auto x : edg_list)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}