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
