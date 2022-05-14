#include <bits/stdc++.h>
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
//#define debug(var)                                                             \
//  do {                                                                         \
//    cout << #var << " : ";                                                     \
//    view(var);                                                                 \
//  } while (0)
#define debug(var)                                                             \
  {}
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
  ll w;
  cin >> w;

  vector<ll> cnt(w + 1);
  REP(i, w + 1) cnt[i] = INF64;

  vector<ll> ans;
  ll nxt = 1;

  while (true) {
    ll now = nxt;
    debug(now);
    nxt = INF64;
    ans.push_back(now);
    debug(ans);

    cnt[now] = 1;
    FOR(i, 1, now - 1) {
      if (i > w)
        break;
      if (cnt[i] < 3) {
        cnt[i + now] = min(cnt[i + now], cnt[i] + 1);
      } else if (cnt[i + now] == INF64) {
        nxt = min(nxt, i + now);
      }
    }
    if (nxt == INF64 && 2 * now - 1 < w)
      nxt = 2 * now;

    if (nxt == INF64)
      break;
  }
  cout << ans.size() << endl;
  cout << ans[0];
  if (ans.size() > 1)
    FOR(i, 1, ans.size() - 1) cout << ' ' << ans[i];
  cout << endl;
  return 0;
}
