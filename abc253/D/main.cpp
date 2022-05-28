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
// 切り上げ
ll iceil(ll a, ll b) { return (a + (b - 1)) / b; }

signed main() {
  ll n, a, b;
  cin >> n >> a >> b;

  if (a > b)
    swap(a, b);

  ll ans = n * (n + 1) / 2;
  ans -= (n / a) * (n / a + 1) / 2 * a;

  if (b % a == 0) {
    cout << ans << endl;
    return 0;
  }

  ans -= (n / b) * (n / b + 1) / 2 * b;
  ll l = lcm(a, b);
  ans += (n / l) * (n / l + 1) / 2 * l;
  cout << ans << endl;
  return 0;
}
