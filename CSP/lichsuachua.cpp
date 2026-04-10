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
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

bool cmp(const pair<ll, ll> &x, const pair<ll, ll> &y)
{
    ll l = x.se * y.fi;
    ll r = y.se * x.fi;
    if (l != r)
        return l < r;
    if (x.fi != y.fi)
        return x.fi < y.fi;
    return x.se < y.se;
}

int main()
{
    fasteio();
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<pair<ll, ll>> j;
    j.reserve(n);
    for (int i = 0; i < n; i++)
        j.push_back({a[i], b[i]});
    sort(j.begin(), j.end(), cmp);
    ll cur = 0;
    ll ans = 0;
    for (auto a : j)
    {
        cur += a.se;
        ans += a.fi * cur;
    }

    cout << ans;
    return 0;
}
