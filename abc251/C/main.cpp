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
template <typename T1, typename T2> void view(const unordered_map<T1, T2> &v) {
  for (const auto &e : v) {
    cout << e.F << ' ' << e.S.F << ' ' << e.S.S << endl;
  }
  cout << endl;
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

  vector<string> s(n);
  vector<ll> t(n);
  REP(i, n) cin >> s[i] >> t[i];

  unordered_map<string, pair<ll, ll>> orig;

  REP(i, n) {
    if (orig.find(s[i]) == orig.end()) {
      orig[s[i]] = make_pair(-t[i], i);
    }
  }

  // debug(orig);

  vector<pair<ll, ll>> orig_list;
  FORA(o, orig) { orig_list.push_back(o.S); }

  // debug(orig_list);

  sort(ALL(orig_list));

  cout << orig_list[0].S + 1 << endl;

  return 0;
}
