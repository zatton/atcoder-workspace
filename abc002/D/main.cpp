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

struct hash_pair {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }
    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};
// unordered_map<pair<ll, ll>, int, hash_pair> hogemap;

signed main() {
  ll n, m;
  cin >> n >> m;
  unordered_map<pair<ll, ll>, int, hash_pair> rel;

  REP(i, m) {
    ll x, y;
    cin >> x >> y;
    rel[make_pair(x - 1, y - 1)] = 1;
  }

  ll ans = 1;

  REP(i, pow(2, n)) {
    bool ok = 1;
    REP(j, n) {
      FOR(k, j + 1, n - 1) {
        if (i >> j & 1 && i >> k & 1) {
          if (rel.find(make_pair(j, k)) == rel.end()) {
            ok = 0;
            break;
          }
        }
      }
      if (!ok)
        break;
    }
    if (ok) {
      ll tmp = 0;
      REP(j, n) if (i >> j & 1) tmp++;

      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;

  return 0;
}
