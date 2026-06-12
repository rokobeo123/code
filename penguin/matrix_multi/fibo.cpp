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
struct matrix {
    ll a[3][3];
};
matrix mul(matrix a, matrix b){
    matrix c;
    for(int i=1; i<=2; i++){
        for(int j=1; j<=2; j++){
            c.a[i][j] = 0;
            for(int k=1; k<=2; k++){
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
            }
        }
    }
    return c;
}
matrix pow(matrix a, ll n){
    if(n == 1) return a;
    matrix c = pow(a, n/2);
    c = mul(c, c);
    if(n % 2) c = mul(c, a);
    return c;
}
int main() {
  fasteio();
    ll n;
    cin >> n;
    if(n==0 || n==1) {
        cout << n;
        return 0;
    }
    matrix a;
    a.a[1][1] = 1; a.a[1][2] = 1;
    a.a[2][1] = 1; a.a[2][2] = 0;
    a = pow(a, n-1);
    cout << a.a[1][1] << endl;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
