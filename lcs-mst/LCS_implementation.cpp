#include <bits/stdc++.h>
using namespace std;

string a, b;

int lcs(int i, int j)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (a[i] == b[j])
    {
        return 1 + lcs(i - 1, j - 1);
    }
    else
    {
        int op_1 = lcs(i - 1, j);
        int op_2 = lcs(i, j - 1);

        return max(op_1, op_2);
    }
}

int main()
{
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    cout << lcs(n - 1, m - 1) << endl;
    return 0;
}

/*
input:
BED
BKE

output:



*/