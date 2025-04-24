#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    int N, E;
    cin >> N >> E;

    int adj_mat[N][N];
    memset(adj_mat, 0, sizeof(adj_mat));

    // set diagonal 1
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 1;
            }
        }
    }

    // input
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        adj_mat[A][B] = 1;
    }

    // check based on Q

    int Q;
    cin >> Q;

    while (Q--)
    {
        int A, B;
        cin >> A >> B;

        if (adj_mat[A][B])
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
