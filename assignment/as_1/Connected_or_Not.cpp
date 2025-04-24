#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input graph
    int N, E;
    cin >> N >> E;

    vector<pair<int, int>> edge_list;

    while (E--)
    {
        int A, B;
        cin >> A >> B;
        edge_list.push_back({A, B});
    }

    // check number of query
    int Q;
    cin >> Q;
    while (Q--)
    {
        int A, B;
        cin >> A >> B;

        // handle corner case for same node
        if (A == B)
        {
            cout << "YES" << endl;
            continue;
        }

        // normal check
        bool found = false;
        for (auto edge : edge_list)
        {
            if (edge.first == A && edge.second == B)
            {
                found = true;
                break;
            }
        }

        if (found)
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