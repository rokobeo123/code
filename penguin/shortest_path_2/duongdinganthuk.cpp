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
const ll INF = 1e18;
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
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<int> ok(n + 1, 0);
    vector<ll> ans;
    pq.push({0, 1});
    while (!pq.empty() && ans.size() < k)
    {
        auto cur = pq.top();
        pq.pop();
        ll dist = cur.fi;
        int u = cur.se;
        if (ok[u] >= k) continue;
        ok[u]++;
        if (u == n)
            ans.pb(dist);
        for (auto e : g[u])
        {
            int v = e.fi;
            ll w = e.se;
            if (ok[v] < k) pq.push({dist + w, v});
        }
    }

    forn(i, ans.size())
    {
        cout << ans[i] << " ";
    }

    return 0;
}
