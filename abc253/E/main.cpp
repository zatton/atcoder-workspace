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
ll modpow(ll a, ll b, ll mod) {
  // a ^ b % mod
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

ll MOD = 998244353;

signed main() {
  ll n, m, k;
  cin >> n >> m >> k;

  if (k == 0) {
    cout << modpow(m, n, MOD) << endl;
    return 0;
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));

  FOR(i, 1, n) FOR(j, 1, m) dp[i][j] = 0;
  FOR(j, 1, m) dp[1][j] = 1;

  FOR(i, 2, n) {
    ll up = 0;
    ll down = 0;

    FOR(j, k + 1, m) {
      up = (dp[i - 1][j - k] + up) % MOD;
      dp[i][j] = (dp[i][j] + up) % MOD;
    }

    FORD(j, m - k, 1) {
      down = (dp[i - 1][j + k] + down) % MOD;
      dp[i][j] = (dp[i][j] + down) % MOD;
    }
  }
  // debug(dp);

  ll ans = 0;
  FOR(j, 1, m) ans = (ans + dp[n][j]) % MOD;
  cout << ans << endl;
  return 0;
}
