#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input node, edge, and graph
    int N, E;
    cin >> N >> E;

    vector<int> adj_list[N]; // Array of vectors

    while (E--)
    {
        int A, B;
        cin >> A >> B;
        adj_list[A].push_back(B);
        adj_list[B].push_back(A);
    }

    // Print based on Q
    int Q;
    cin >> Q;

    while (Q--)
    {
        int X;
        cin >> X;

        if (adj_list[X].size() == 0) // If no connections
        {
            cout << "-1" << endl;
        }
        else
        {
            vector<int> edge_list = adj_list[X];
            sort(edge_list.begin(), edge_list.end(), greater<int>()); // Descending sort

            for (int node : edge_list)
            {
                cout << node << " ";
            }
            cout << "" << endl;
        }
    }

    return 0;
}
