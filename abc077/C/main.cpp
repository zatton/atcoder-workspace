#include <algorithm>
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
  vector<ll> A, B, C;

  REP(i, n) {
    ll a;
    cin >> a;
    A.push_back(a);
  }
  REP(i, n) {
    ll b;
    cin >> b;
    B.push_back(b);
  }
  REP(i, n) {
    ll c;
    cin >> c;
    C.push_back(c);
  }

  sort(ALL(A));
  sort(ALL(C));

  ll ans = 0;

  REP(i, n) {
    ll b = B[i];
    auto l = lower_bound(ALL(A), b);
    auto u = upper_bound(ALL(C), b);

    debug(*l);
    debug(*u);

    ll lcnt = distance(A.begin(), l);
    debug(lcnt);

    ll ucnt = distance(u, C.end());
    debug(ucnt);

    ans += (lcnt * ucnt);
  }

  cout << ans << endl;
  return 0;
}
