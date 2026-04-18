#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define endl '\n'
#define fasteio()                      \
  ios::sync_with_stdio(false);         \
  cin.tie(nullptr);                    \
  cout.tie(nullptr);

static const int K = 50;

struct Node {
  int len;
  int val[K];
  Node() : len(0) {}
};

Node mergeNode(const Node &left, const Node &right) {
  Node res;
  int i = 0, j = 0;
  while (res.len < K && (i < left.len || j < right.len)) {
    if (j == right.len || (i < left.len && left.val[i] > right.val[j])) {
      res.val[res.len++] = left.val[i++];
    } else {
      res.val[res.len++] = right.val[j++];
    }
  }
  return res;
}

Node makeLeaf(int x) {
  Node res;
  res.len = 1;
  res.val[0] = x;
  return res;
}

ll bestTriangle(const Node &node) {
  if (node.len < 3) return 0;
  int arr[K];
  for (int i = 0; i < node.len; ++i) arr[i] = node.val[i];
  reverse(arr, arr + node.len);
  for (int i = node.len - 1; i >= 2; --i) {
    if (1LL * arr[i - 2] + arr[i - 1] > arr[i]) {
      return 1LL * arr[i - 2] + arr[i - 1] + arr[i];
    }
  }
  return 0;
}

int main() {
  fasteio();

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int size = 1;
  while (size < n) size <<= 1;
  vector<Node> st(size << 1);

  for (int i = 0; i < n; ++i) st[size + i] = makeLeaf(a[i]);
  for (int i = size - 1; i >= 1; --i) st[i] = mergeNode(st[i << 1], st[i << 1 | 1]);

  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 0) {
      int pos = size + x;
      st[pos] = makeLeaf(y);
      for (pos >>= 1; pos >= 1; pos >>= 1) {
        st[pos] = mergeNode(st[pos << 1], st[pos << 1 | 1]);
        if (pos == 1) break;
      }
    } else {
      int l = x + size;
      int r = y + size + 1;
      Node leftRes, rightRes;
      while (l < r) {
        if (l & 1) leftRes = mergeNode(leftRes, st[l++]);
        if (r & 1) rightRes = mergeNode(st[--r], rightRes);
        l >>= 1;
        r >>= 1;
      }
      Node whole = mergeNode(leftRes, rightRes);
      cout << bestTriangle(whole) << endl;
    }
  }

  return 0;
}
