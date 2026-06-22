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

int main() {
  fasteio();
    string s;
    cin >> s;
    ll dai=s.size();
    s = " " + s;
    ll it=1;
    while(it <= 9){
        if( it > dai){
            cout << it;
            return 0;
        }
        if(it==1 || it==2){
            if(s[it] >= 'A' && s[it] <= 'Z') it++;
            else{
                cout << it;
                return 0;
            }
        }
        else if (it==3){
            if(s[it] == '-') it++;
            else{
                cout << it;
                return 0;
            }
        }
        else if(it==4 || it==5 || it==6){
            if(s[it] >= '0' && s[it] <= '9') it++;
            else{
                cout << it;
                return 0;
            }
        }
        else if(it==7){
            if(s[it] == '.') it++;
            else{
                cout << it;
                return 0;
            }
        }
        else if(it==8 || it==9){
            if(s[it] >= '0' && s[it] <= '9') it++;
            else{
                cout << it;
                return 0;
            }
        }
    }
    if(it == 10 && dai==9) cout << "0";
    else cout << it;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
