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
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
// 切り上げ
ll iceil(ll a, ll b) { return (a + (b - 1)) / b; }

signed main() {
  ll n;
  cin >> n;

  vector<ll> s(n), h(n);
  REP(i, n) { cin >> s[i] >> h[i]; }

  ll max_cost = INF64;
  ll min_cost = 0;

  while (min_cost + 1 < max_cost) {
    // check half
    bool ok = true;
    ll check_cost = (min_cost + max_cost) / 2;

    vector<ll> limit_time(n);
    REP(i, n) {
      // check_cost < s[i]かつh[i]が大きい場合は
      // limit_timeが0になってしまうことがあるので注意
      if (check_cost < s[i])
        ok = 0;
      limit_time[i] = (check_cost - s[i]) / h[i];
    }
    sort(ALL(limit_time));

    REP(j, n) {
      if (limit_time[j] < j) {
        ok = false;
        min_cost = check_cost;
        break;
      }
    }

    if (ok) {
      max_cost = check_cost;
    } else
      min_cost = check_cost;
  }

  cout << max_cost << endl;

  return 0;
}
