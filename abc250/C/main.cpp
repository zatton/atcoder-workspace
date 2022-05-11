#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= ll(b); i--)
#define FORA(i, I) for (const auto &i : I)
#define ALL(x) x.begin(), x.end()
#define SIZE(x) ll(x.size())
#define INF32 2147483647
#define INF64 9223372036854775807
//#define MOD 1000000007
#define F first
#define S second
#define debug(var)                                                             \
  do {                                                                         \
    cout << #var << " : ";                                                     \
    view(var);                                                                 \
  } while (0)
//#define debug(var) {}
template <typename T> void view(T e) { cout << e << endl; }
template <typename T1, typename T2> void view(const pair<T1, T2> &v) {
  cout << v.F << ' ' << v.S << endl;
}
template <typename T> void view(const vector<T> &v) {
  for (const auto &e : v) {
    cout << e << " ";
  }
  cout << endl;
}
template <typename T> void view(const vector<vector<T>> &vv) {
  for (const auto &v : vv) {
    view(v);
  }
}

signed main() {
  ll n, q;
  cin >> n >> q;

  ll ans[n];
  unordered_map<ll, ll> loc;

  REP(i, n) {
    ans[i] = i;
    loc[i] = i;
  }

  REP(i, q) {
    ll x;
    cin >> x;
    x--;

    auto l = loc[x];
    auto lval = x;
    if (l == n - 1)
      l--;

    auto rval = ans[l + 1];

    // l番目とl + 1番目を入れ替える
    swap(ans[l], ans[l + 1]);
    loc[lval] = l + 1;
    loc[rval] = l;

    // REP(j, n) cout << ans[j] + 1 << ' ';
    // cout << endl;
  }

  REP(i, n) cout << ans[i] + 1 << ' ';
  cout << endl;
  return 0;
}
