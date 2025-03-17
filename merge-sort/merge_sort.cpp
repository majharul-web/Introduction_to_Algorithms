#include <bits/stdc++.h>
using namespace std;

void conquer(vector<int> &c, int l, int mid, int r)
{
    int n = mid - l + 1;
    int m = r - mid;

    vector<int> a(n);
    vector<int> b(m);

    int k = l;
    for (int i = 0; i < n; i++, k++)
    {
        a[i] = c[k];
    }

    int k_2 = mid + 1;
    for (int i = 0; i < m; i++, k_2++)
    {
        b[i] = c[k_2];
    }

    int i = 0, j = 0, curr = l;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[curr++] = a[i++];
        }
        else
        {
            c[curr++] = b[j++];
        }
    }

    while (i < n)
    {
        c[curr++] = a[i++];
    }
    while (j < m)
    {
        c[curr++] = b[j++];
    }
}

void divide(vector<int> &a, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int mid = (l + r) / 2;

    divide(a, l, mid);
    divide(a, mid + 1, r);
    conquer(a, l, mid, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    divide(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

/*
input
5
30 9 1 7 4

output:
1 4 7 9 30

*/