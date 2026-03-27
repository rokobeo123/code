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

vector<ll> a, b;

bool cmpp(int i, int j)
{
    if (a[i] != a[j])
        return a[i] < a[j];
    return i < j;
}

bool cmpnp(int i, int j)
{
    if (b[i] != b[j])
        return b[i] > b[j];
    if (a[i] != a[j])
        return a[i] < a[j];
    return i < j;
}

int main()
{
    fasteio();
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> p, np;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= b[i])
            p.push_back(i);
        else
            np.push_back(i);
    }
    sort(p.begin(), p.end(), cmpp);
    sort(np.begin(), np.end(), cmpnp);
    vector<int> o;
    for (int idx : p)
        o.push_back(idx);
    for (int idx : np)
        o.push_back(idx);
    ll cur = 0;
    ll mc = 0;
    for (int idx : o)
    {
        cur = cur - a[idx] + b[idx];
        mc = min(mc, cur);
    }
    ll cnt = -mc;
    cout << cnt << "\n";
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << o[i] + 1;
    }
    cout << "\n";

    return 0;
}
