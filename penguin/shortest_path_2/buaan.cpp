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

    vector<vector<pair<int, int>>> g(n + 1);
    forn(i, m)
    {
        int a, b, t;
        cin >> a >> b >> t;
        g[a].pb({b, t});
        g[b].pb({a, t});
    }

    vector<pair<int, ll>> hay(k);
    forn(i, k)
    {
        int x;
        ll y;
        cin >> x >> y;
        hay[i] = {x, y};
    }

    auto dijkstra = [&](const vector<ll> &startDist)
    {
        vector<ll> dist = startDist;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

        for1(v, n)
        {
            if (dist[v] < INF)
                pq.push({dist[v], v});
        }

        while (!pq.empty())
        {
            auto [du, u] = pq.top();
            pq.pop();
            if (du != dist[u])
                continue;

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
    };

    vector<ll> start(n + 1, INF);
    start[n] = 0;
    vector<ll> d = dijkstra(start);

    vector<ll> b(n + 1, INF);
    for (auto [x, y] : hay)
    {
        b[x] = min(b[x], d[x] - y);
    }
    vector<ll> best = dijkstra(b);

    for1(i, n - 1)
    {
        cout << (best[i] <= d[i] ? 1 : 0) << '\n';
    }

    return 0;
}
