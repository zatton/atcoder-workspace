#include <bits/stdc++.h>
#include <utility>
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
  vector<pair<ll, ll>> want;
  unordered_map<ll, int> candi;

  REP(i, n) {
    ll a, b;
    cin >> a >> b;
    want.push_back(make_pair(a, b));
    candi[a] = 1;
    candi[b] = 1;
  }

  ll ans = INF64;

  FORA(i, candi) {
    FORA(j, candi) {
      ll st = i.F;
      ll en = j.F;

      debug(st);
      debug(en);

      ll tmp = 0;

      FORA(w, want) {
        ll a = w.F;
        ll b = w.S;
        ll tmpw = INF64;

        // st -> a -> b -> en
        tmpw = min(tmpw, abs(a - st) + abs(b - a) + abs(en - b));
        // st -> b -> a -> en
        tmpw = min(tmpw, abs(b - st) + abs(a - b) + abs(en - a));

        tmp += tmpw;
      }
      debug(tmp);
      ans = min(ans, tmp);
    }
  }

  cout << ans << endl;
  return 0;
}
