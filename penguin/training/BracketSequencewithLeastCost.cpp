#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unordered_map
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

int main(){
  ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            int x, y;
            cin >> x >> y;
            a.push_back(x);
            b.push_back(y);
        }
    }
    int idx = 0;
    int balance = 0;
    int cost = 0;
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            balance++;
        }
        else if(s[i] == ')'){
            balance--;
        }
        else{
            cost += b[idx];
            balance--;
            pq.push({b[idx] - a[idx], i});
            s[i] = ')';
            idx++;
        }
        if(balance < 0){
            if(pq.empty()){
                cout << -1;
                return 0;
            }
            auto [val, pos] = pq.top(); pq.pop();
            cost -= val;
            s[pos] = '(';
            balance += 2;
        }
    }
    if(balance != 0){
        cout << -1;
        return 0;
    }
    cout << cost << endl;
    cout << s;
}
