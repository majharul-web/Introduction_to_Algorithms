#include <bits/stdc++.h>
using namespace std;

void divide(int a[], int l, int r)
{

    for (int i = l; i <= r; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    if (l >= r)
    {
        return;
    }

    int mid = (l + r) / 2;

    divide(a, l, mid);
    divide(a, mid + 1, r);
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    divide(a, 0, n - 1);

    return 0;
}

/*
complexity: O(log N)

input
5
30 9 1 7 4

output:
30 9 1 7 4
30 9 1
30 9
30
9
1
7 4
7
4
*/
