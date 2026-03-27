#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unoed_map
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

int main()
{
    fasteio();

    int n;
    cin >> n;

    vector<ll> a(n + 1), b(n + 1);
    for1(i, n) cin >> a[i];
    for1(i, n) cin >> b[i];

    vector<pair<ll, int>> l, r;
    l.reserve(n);
    r.reserve(n);
    for1(i, n)
    {
        if (a[i] <= b[i])
        {
            l.pb({a[i], i});
        }
        else
        {
            r.pb({b[i], i});
        }
    }

    sort(all(l));
    sort(allr(r));

    vector<int> o;
    o.reserve(n);
    for (auto &p : l)
        o.pb(p.se);
    for (auto &p : r)
        o.pb(p.se);

    ll fu = 0;
    ll fd = 0;
    for (int id : o)
    {
        fu += a[id];
        fd = max(fd, fu) + b[id];
    }

    cout << fd << '\n';
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << ' ';
        cout << o[i];
    }
    cout << '\n';

    return 0;
}
