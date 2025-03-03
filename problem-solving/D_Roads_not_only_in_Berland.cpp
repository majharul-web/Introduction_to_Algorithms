#include <bits/stdc++.h>
using namespace std;

int par[10005];
int group_size[10005];

void dsu_init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}

int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)

{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (leader1 == leader2)
    {
        return;
    }

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

    int n;
    cin >> n;

    dsu_init(n);

    vector<pair<int, int>> remove_list;
    vector<pair<int, int>> create_list;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        int par_u = find(u);
        int par_v = find(v);

        if (par_u == par_v)
        {
            remove_list.push_back({u, v});
        }
        else
        {
            dsu_union(u, v);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int par_u = find(1);
        int par_v = find(i);

        if (par_u != par_v)
        {
            create_list.push_back({1, i});
            dsu_union(1, i);
        }
    }
    cout << remove_list.size() << endl;

    for (int i = 0; i < remove_list.size(); i++)
    {
        cout << remove_list[i].first << " " << remove_list[i].second << " " << create_list[i].first << " " << create_list[i].second << endl;
    }
}