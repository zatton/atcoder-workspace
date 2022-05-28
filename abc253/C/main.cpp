#include <bits/stdc++.h>
#include <unordered_map>
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
  ll q;
  cin >> q;
  map<ll, ll> s;

  REP(i, q) {
    ll t;
    cin >> t;

    if (t == 1) {
      ll x;
      cin >> x;
      if (s.find(x) != s.end()) {
        s[x]++;
      } else {
        s[x] = 1;
      }
      continue;
    }

    if (t == 2) {
      ll x, c;
      cin >> x >> c;
      if (auto it = s.find(x); it != s.end()) {
        if (s[x] > c)
          s[x] -= c;
        else
          s.erase(it);
      }
      continue;
    }

    if (t == 3) {
      // cout << s.rbegin()->first << ' ' << s.begin()->first << endl;
      cout << (s.rbegin()->first) - (s.begin()->first) << endl;
    }
  }

  return 0;
}
