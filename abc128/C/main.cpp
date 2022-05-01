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
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> swl;
  vector<ll> odd;

  REP(i, m) {
    ll k;
    cin >> k;
    vector<ll> tmp;
    REP(j, k) {
      ll p;
      cin >> p;
      tmp.push_back(p);
    }
    swl.push_back(tmp);
  }

  debug(swl);

  REP(i, m) {
    ll p;
    cin >> p;
    odd.push_back(p);
  }

  debug(odd);

  ll ans = 0;
  REP(i, pow(2, n)) {
    // cout << endl << i << endl;
    bool ok = 1;
    REP(j, m) {
      ll tmp = 0;
      FORA(k, swl[j]) {
        if (i >> (k - 1) & 1)
          tmp++;
      }
      if (tmp % 2 != odd[j]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
