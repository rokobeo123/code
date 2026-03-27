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
const ll INF = (ll)4e18;
const ll MOD = 1e9 + 7;

int main()
{
    fasteio();

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> g(n + 1);
    forn(i, m)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
    }
    vector<ll> dist(n + 1, INF), a(n + 1, 0);
    vector<int> cntmin(n + 1, INT_MAX), cntmax(n + 1, INT_MIN);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[1] = 0;
    a[1] = 1;
    cntmin[1] = 0;
    cntmax[1] = 0;
#include <bits/stdc++.h>
using namespace std;

    using ll = long long;

    struct Edge
    {
        int u, v;
        ll w;
    };

    static const ll INF = (ll)4e18;

    vector<ll> dijkstra(int n, int src, const vector<vector<pair<int, ll>>> &g)
    {
        vector<ll> dist(n + 1, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto [du, u] = pq.top();
            pq.pop();
            if (du != dist[u])
            {
                continue;
            }
            for (auto [v, w] : g[u])
            {
                if (dist[v] > du + w)
                {
                    dist[v] = du + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    ll solve_ordered(int n, const vector<vector<int>> &dag, const vector<int> &order,
                     const vector<char> &on_sp, const vector<ll> &f,
                     const vector<ll> &g)
    {
        vector<ll> best(n + 1, INF);
        ll ans = INF;

        for (int u : order)
        {
            if (!on_sp[u])
            {
                continue;
            }
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
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, m;
        cin >> n >> m;

        int s, t;
        cin >> s >> t;

        int u, v;
        cin >> u >> v;

        vector<vector<pair<int, ll>>> graph(n + 1);
        vector<Edge> edges;
        edges.reserve(m);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
            edges.push_back({a, b, c});
        }

        vector<ll> dS = dijkstra(n, s, graph);
        vector<ll> dT = dijkstra(n, t, graph);
        vector<ll> dU = dijkstra(n, u, graph);
        vector<ll> dV = dijkstra(n, v, graph);

        ll shortest_ST = dS[t];

        vector<char> on_shortest_path(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (dS[i] + dT[i] == shortest_ST)
            {
                on_shortest_path[i] = 1;
            }
        }

        vector<vector<int>> dag(n + 1);
        for (const auto &e : edges)
        {
            int a = e.u;
            int b = e.v;
            ll w = e.w;

            if (dS[a] + w + dT[b] == shortest_ST)
            {
                dag[a].push_back(b);
            }
            if (dS[b] + w + dT[a] == shortest_ST)
            {
                dag[b].push_back(a);
            }
        }

        vector<int> order;
        order.reserve(n);
        for (int i = 1; i <= n; i++)
        {
            if (on_shortest_path[i])
            {
                order.push_back(i);
            }
        }
        sort(order.begin(), order.end(), [&](int x, int y)
             { return dS[x] < dS[y]; });

        ll ans = dU[v];
        ans = min(ans, solve_ordered(n, dag, order, on_shortest_path, dU, dV));
        ans = min(ans, solve_ordered(n, dag, order, on_shortest_path, dV, dU));

        cout << ans << '\n';
        return 0;
    }

    pq.push({0, 1});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll d = cur.fi;
        int u = cur.se;
        for (auto e : g[u])
        {
            int v = e.fi;
            ll w = e.se;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                a[v] = a[u];
                cntmin[v] = cntmin[u] + 1;
                cntmax[v] = cntmax[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[v] == d + w)
            {
                a[v] = (a[v] + a[u]) % MOD;
                cntmin[v] = min(cntmin[v], cntmin[u] + 1);
                cntmax[v] = max(cntmax[v], cntmax[u] + 1);
            }
        }
    }
    return 0;
}
