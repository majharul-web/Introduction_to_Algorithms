#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<pair<ll, ll>> adj_list[100005];
ll dis[100005];
ll par[100005];

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        ll par_node = cur.second;
        ll par_dis = cur.first;

        for (auto child : adj_list[par_node])
        {
            ll child_node = child.first;
            ll child_dis = child.second;

            ll dist = par_dis + child_dis;

            if (dist < dis[child_node])
            {
                dis[child_node] = dist;
                pq.push({dist, child_node});
                par[child_node] = par_node;
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;

    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for (ll i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
        par[i] = -1;
    }

    dijkstra(1);

    if (dis[n] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<ll> path;
        ll node = n;
        while (node != -1)
        {
            path.push_back(node);
            node = par[node];
        }
        reverse(path.begin(), path.end());

        for (auto x : path)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
