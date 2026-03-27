#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unordered_map
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ford(i, a, b) for (int i = int(a); i >= int(b); i--)
#define allr(x) x.rbegin(), x.rend()
#define fasteio()                \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
void fre(const char *tenbai)
{
    string input_file = string(tenbai) + ".INP";
    string output_file = string(tenbai) + ".OUT";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}
struct edge
{
    int u, v;
    ll w;
};
vector<edge> edges;
vector<vector<pair<int, ll>>> g(100001);
const ll INF = 4e18;
const ll MOD = 1e9 + 7;
vector<ll> dijkstra(ll start, ll src)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(start + 1, INF);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll d = cur.fi;
        int u = cur.se;
        if (d != dist[u])
            continue;
        for (auto e : g[u])
        {
            int v = e.fi;
            ll w = e.se;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
vector<vector<int>> dag(100001);
vector<int> order;
vector<ll> ds, dt, du, dv;
bool cmp(int a, int b)
{
    return ds[a] < ds[b];
}
ll n, m;
ll kq(vector<ll> &f, vector<ll> &g)
{
    vector<ll> best(n + 1, INF);
    ll ans = INF;
    for (int u : order)
    {
        best[u] = min(best[u], f[u]);
        if (best[u] < INF)
        {
            ans = min(ans, best[u] + g[u]);
        }
        for (int v : dag[u])
        {
            if (best[v] > best[u])
            {
                best[v] = best[u];
            }
        }
    }
    return ans;
}
int main()
{
    fasteio();
    cin >> n >> m;
    ll s, t;
    cin >> s >> t;
    ll u, v;
    cin >> u >> v;
    forn(i, m)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
        edges.pb({a, b, c});
    }
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    ds = dijkstra(n, s);
    dt = dijkstra(n, t);
    du = dijkstra(n, u);
    dv = dijkstra(n, v);
    ll ans = du[v];
    vector<ll> path(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (ds[i] + dt[i] == ds[t])
        {
            path[i] = 1;
        }
    }

    for (auto e : edges)
    {
        int a = e.u;
        int b = e.v;
        ll w = e.w;
        if (ds[a] + w + dt[b] == ds[t])
        {
            dag[a].pb(b);
        }
        if (ds[b] + w + dt[a] == ds[t])
        {
            dag[b].pb(a);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (path[i])
            order.pb(i);
    }
    sort(all(order), cmp);
    ans = min(ans, kq(du, dv));
    ans = min(ans, kq(dv, du));
    cout << ans << "\n";
    return 0;
}
