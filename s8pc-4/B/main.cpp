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
  ll n, k;
  cin >> n >> k;
  vector<ll> a;
  REP(i, n) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  ll ans = INF64;
  REP(i, pow(2, n)) {
    ll tmp = 0;
    REP(j, n) {
      if (i >> j & 1)
        tmp++;
    }
    debug(tmp);
    if (tmp < k)
      continue;

    ll now = 0;
    ll cost = 0;
    REP(j, n) {
      if (i >> j & 1) {
        if (a[j] > now) {
          now = a[j];
        } else {
          now++;
          cost += (now - a[j]);
        }
        debug(now);
      } else if (a[j] > now)
        now = a[j];
    }
    debug(cost);
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
