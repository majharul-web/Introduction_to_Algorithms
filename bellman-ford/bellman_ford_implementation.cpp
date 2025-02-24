#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dist[1005];
vector<Edge> edge_list;
int n, e;

void bellman_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edge_list)
        {
            int a, b, c;
            a = edge.a;
            b = edge.b;
            c = edge.c;

            if (dist[a] != INT_MAX && dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
            }
        }
    }
}

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); //for undirected
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0; // Source node assumed to be 0

    bellman_ford();
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
    }

    return 0;
}

/*

input:
4 4
0 2 5
0 3 12
2 1 2
1 3 3

output:

0 -> 0
1 -> 7
2 -> 5
3 -> 10


complexity: O(VE)


*/