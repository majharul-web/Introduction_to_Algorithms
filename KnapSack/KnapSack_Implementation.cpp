#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];

int knapSack(int i, int max_weight)
{
    if (i < 0 || max_weight <= 0)
    {
        return 0;
    }
    if (weight[i] <= max_weight)
    {
        int op_1 = val[i] + knapSack(i - 1, max_weight - weight[i]);
        int op_2 = knapSack(i - 1, max_weight);
        return max(op_1, op_2);
    }
    else
    {
        return knapSack(i - 1, max_weight);
    }
}

int main()
{
    int n, max_wight;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cin >> max_wight;

    int result = knapSack(n - 1, max_wight);
    cout << result << endl;

    return 0;
}

/*
input:
4
10 4 7 5
4 3 2 5
8

output:
17


Complexity: O (2^N)

*/
