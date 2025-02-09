#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj_list(N); // adj list

    for (int i = 0; i < M; i++) // input
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for (int i = 0; i < N; i++) // sort acending order
    {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    // input Q and print finall output
    int Q;
    cin >> Q;

    while (Q--)
    {
        int x;
        cin >> x;

        if (adj_list[x].size() == 0)
        {
            cout << "No connections" << endl;
        }
        else
        {
            for (int c : adj_list[x])
            {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
