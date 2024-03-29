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
  ll n;
  cin >> n;
  vector<ll> A(n);
  REP(i, n) cin >> A[i];

  vector<vector<ll>> dp(n);
  REP(i, n) REP(j, 2) dp[i].push_back(0);

  // A0を使用
  dp[0][0] = INF32;
  dp[0][1] = A[0];
  FOR(i, 1, n - 1) {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = min(dp[i - 1][1] + A[i], dp[i - 1][0] + A[i]);
  }
  debug(dp);

  ll ans = min(dp[n - 1][0], dp[n - 1][1]);

  REP(i, n) REP(j, 2) dp[i][j] = 0;

  // A0を使用しない
  dp[0][0] = 0;
  dp[0][1] = INF32;
  FOR(i, 1, n - 1) {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = min(dp[i - 1][1] + A[i], dp[i - 1][0] + A[i]);
  }
  debug(dp);
  ans = min(ans, dp[n - 1][1]);

  cout << ans << endl;

  return 0;
}
