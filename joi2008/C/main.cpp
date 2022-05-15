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

signed main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> p(n);
  REP(i, n) cin >> p[i];

  set<ll> avail;
  REP(i, n) avail.insert(p[i]);
  REP(i, n) REP(j, n) avail.insert(p[i] + p[j]);

  vector<ll> av;
  FORA(a, avail) av.push_back(a);
  sort(ALL(av));

  ll ans = 0;
  auto it = lower_bound(ALL(av), m);
  if (*it != m) {
    if (it != av.begin()) {
      it--;
      ans = *it;
    } else
      ans = 0;
  } else
    ans = *it;

  FORA(a, av) {
    auto it = lower_bound(ALL(av), m - a);
    if (*it != m - a) {
      if (it != av.begin())
        it--;
      else
        continue;
    }
    ans = max(ans, a + *it);
  }

  cout << ans << endl;

  return 0;
}
