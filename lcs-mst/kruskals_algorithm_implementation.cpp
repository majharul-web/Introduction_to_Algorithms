#include <bits/stdc++.h>
using namespace std;

int par[1005];
int group_size[1005];

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

bool cmp(Edge l, Edge r)
{
    return l.c < r.c;
}

int find(int node)
{

    if (par[node] == -1)
    {
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void set_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{

    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    sort(edge_list.begin(), edge_list.end(), cmp);

    int totalCost = 0;

    // Print sorted edges
    for (auto edge : edge_list)
    {
        int parA = find(edge.a);
        int parB = find(edge.b);

        if (parA != parB)
        {
            set_union(edge.a, edge.b);
            totalCost += edge.c;
        }
        // cout << edge.a << " " << edge.b << " " << edge.c << endl;
    }

    cout << "Total Cost : " << totalCost << endl;

    return 0;
}

/*
input:
4 5
1 2 10
2 3 5
3 4 8
1 3 7
2 4 6


output:
18


*/
