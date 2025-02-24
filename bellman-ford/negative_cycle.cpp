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

void bellman_ford(int source)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edge_list)
        {
            int a = edge.a, b = edge.b, c = edge.c;

            if (dist[a] != INT_MAX && dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
            }
        }
    }

    bool cycle = false;

    for (auto edge : edge_list)
    {
        int a = edge.a, b = edge.b, c = edge.c;

        if (dist[a] != INT_MAX && dist[a] + c < dist[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative cycle detected\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << "\n";
        }
    }
}

int main()
{
    cin >> n >> e;
    int source = 0; // Default source node
    cin >> source;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); // Uncomment if undirected
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    bellman_ford(source);

    return 0;
}

/*
Input Example:
4 4
0
0 1 5
0 2 3
2 3 2
3 1 -6

Expected Output:
0 -> 0
1 -> -1
2 -> 3
3 -> 5

input :
4 4
0
0 1 1
1 2 -1
2 3 -1
3 1 -1

output:

Negative cycle detected

Complexity: O(VE)
*/
