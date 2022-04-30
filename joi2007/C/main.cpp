#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//イテレーション
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= ll(b); i--)
#define FORA(i, I) for (const auto &i : I)
// x:コンテナ
#define ALL(x) x.begin(), x.end()
#define SIZE(x) ll(x.size())
//定数
#define INF32 2147483647          // 2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 // 9.223372036854775807×10^{18}:64bit整数のinf
//#define MOD 1000000007 //問題による
//略記
#define F first
#define S second
//出力(空白区切りで昇順に)
#define coutALL(x)                                                             \
  {                                                                            \
    for (auto i = x.begin(); i != --x.end(); i++)                              \
      cout << *i << " ";                                                       \
    cout << *--x.end() << endl;                                                \
  }

void solve() {
  ll n;
  cin >> n;

  // cout << n << endl;

  map<pair<ll, ll>, ll> poles;

  REP(i, n) {
    ll x, y;
    cin >> x >> y;
    poles[make_pair(x, y)] = 1;
  }

  ll ans = 0;

  for (auto i = poles.begin(); i != poles.end(); i++) {
    for (auto j = i; j != poles.end(); j++) {
      auto x1 = i->first.first;
      auto y1 = i->first.second;
      auto x2 = j->first.first;
      auto y2 = j->first.second;

      ll a = y1 - y2;
      ll b = x2 - x1;

      if (poles.find(make_pair(x2 - a, y2 - b)) != poles.end() &&
          poles.find(make_pair(x1 - a, y1 - b)) != poles.end()) {
        // success
        ll sp =
            (max({x1, x2, x1 - a, x2 - a}) - min({x1, x2, x1 - a, x2 - a})) *
                (max({y1, y2, y1 - b, y2 - b}) -
                 min({y1, y2, y1 - b, y2 - b})) -
            abs(a) * abs(b) * 2;
        ans = max(ans, sp);
      }
    }
  }
  cout << ans << endl;
}

signed main() {
  solve();
  return 0;
}
