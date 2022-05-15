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

  if (n % 2 == 0) {
    ll ans1 = 0, ans2 = 0;
    REP(i, n / 2) ans1 += A[2 * i];
    REP(i, n / 2) ans2 += A[2 * i + 1];
    cout << min(ans1, ans2) << endl;
    return 0;
  }

  // 0番目重複
  ll ans = 0;
  REP(i, n / 2) ans += A[2 * i];
  ans += A[n - 1];

  ll tmp = ans;
  debug(tmp);

  // i番目重複 (偶数)
  for (ll i = 2; i < n; i += 2) {
    tmp -= A[i - 2];
    debug(tmp);
    tmp += A[i - 1];
    debug(tmp);
    ans = min(ans, tmp);
  }

  // 1番目重複
  tmp = 0;
  REP(i, n / 2) tmp += A[2 * i + 1];
  tmp += A[0];
  debug(tmp);

  // i番目重複 (偶数)
  for (ll i = 3; i < n; i += 2) {
    tmp -= A[i - 2];
    tmp += A[i - 1];
    debug(tmp);
    ans = min(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
