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
    ll a[7][7];
};
matrix mul(matrix a, matrix b){
    matrix c;
    for(int i=1; i<=6; i++){
        for(int j=1; j<=6; j++){
            c.a[i][j] = 0;
            for(int k=1; k<=6; k++){
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
            }
        }
    }
    return c;
}
matrix pow(matrix a, ll n){
    if(n==0){
        matrix c;
        for(int i=1; i<=6; i++){
            for(int j=1; j<=6; j++){
                c.a[i][j] = (i==j);
            }
        }
        return c;
    }
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
    matrix a;
    a.a[1][1] = 1; a.a[1][2] = 1; a.a[1][3] = 1; a.a[1][4] = 1; a.a[1][5] = 1; a.a[1][6] = 1;
    a.a[2][1] = 1; a.a[2][2] = 0; a.a[2][3] = 0; a.a[2][4] = 0; a.a[2][5] = 0; a.a[2][6] = 0;
    a.a[3][1] = 0; a.a[3][2] = 1; a.a[3][3] = 0; a.a[3][4] = 0; a.a[3][5] = 0; a.a[3][6] = 0;
    a.a[4][1] = 0; a.a[4][2] = 0; a.a[4][3] = 1; a.a[4][4] = 0; a.a[4][5] = 0; a.a[4][6] = 0;
    a.a[5][1] = 0; a.a[5][2] = 0; a.a[5][3] = 0; a.a[5][4] = 1; a.a[5][5] = 0; a.a[5][6] = 0;
    a.a[6][1] = 0; a.a[6][2] = 0; a.a[6][3] = 0; a.a[6][4] = 0; a.a[6][5] = 1; a.a[6][6] = 0;
    a = pow(a, n);
    cout << a.a[1][1] % MOD << endl;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
