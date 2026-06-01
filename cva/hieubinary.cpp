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
string a,b;
void xoa(string &s){
    ll pos=0;
    while(pos<s.size()-1&&s[pos]=='0'){
        pos++;
    }
    s=s.substr(pos);
}
void add(string &a, string &b){
    while(b.size()<a.size()){
        b='0'+b;
    }
    while(a.size()<b.size()){
        a='0'+a;
    }
}
string ans="";
void hieubinary(string a, string b){
    ll nho=0;
    for(int i=a.size()-1;i>=0;i--){
        ll x=a[i]-'0';
        ll y=b[i]-'0';
        ll sum=x-y-nho;
        if(sum<0){
            sum+=2;
            nho=1;
        }
        else{
            nho=0;
        }
        ans+=char(sum+'0');
    }
    reverse(ans.begin(), ans.end());
    ll pos=0;
    while(pos<ans.size()-1&&ans[pos]=='0'){
        pos++;
    }
    ans=ans.substr(pos);
}
int main() {
    //fre("BAI2");
  fasteio();
    cin >> a >> b;
    xoa(a);
    xoa(b);
    add(a,b);
    if(a==b){
        cout << 0;
        return 0;
    }
    if(a > b){
        hieubinary(a,b);
        cout << ans;
    }
    else{
        hieubinary(b,a);
            cout << '-' << ans;
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
