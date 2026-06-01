    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define pb push_back
    #define mp make_pair
    #define all(x) x.begin(), x.end()
    #define fi first
    #define se second
    #define umap unordered_map
    #define endl '\n'
    #define allr(x) x.rbegin(), x.rend()
    #define fasteio()                                                              \
    ios::sync_with_stdio(false);                                                 \
    cin.tie(nullptr);                                                            \
    cout.tie(nullptr);
    void fre(const char *tenbai) {
    string input_file = string(tenbai) + ".INP";
    string output_file = string(tenbai) + ".OUT";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
    }
    const ll INF = 1e9;
    const ll MOD = 1e9 +7;
    const ll maxn = 1e5 + 5;
    vector<ll> adj[maxn];
    ll color[maxn];
    bool dfs(ll u,ll c){
        color[u]= c;
        for(auto v : adj[u]){
            if(color[v] == c) return false;
            if(color[v]==0){
                if(!dfs(v, 3 - c)) return false;
            }
        }
        return true;
    }
    int main() {
    fasteio();
    ll n,m;
    cin >> n >> m;
        for(int i = 0; i < m; i++){
            ll u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i = 1; i <= n; i++){
            if(color[i] == 0){
                if(!dfs(i, 1)){
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            cout << color[i] << " ";
        }
    //cerr << 1000 * clock() / CLOCKS_PER_SEC;
    return 0;
    }
