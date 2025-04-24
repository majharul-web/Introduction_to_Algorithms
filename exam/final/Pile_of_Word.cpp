#include <bits/stdc++.h>
using namespace std;

bool is_same_to_same(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (is_same_to_same(s1, s2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
