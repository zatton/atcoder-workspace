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
  ll r, c;
  cin >> r >> c;

  vector<vector<bool>> cond;

  REP(i, r) {
    vector<bool> tmp;
    REP(j, c) {
      bool c;
      cin >> c;
      tmp.push_back(c);
    }
    cond.push_back(tmp);
  }

  ll ans = 0;

  REP(j, pow(2, r)) {
    vector<vector<bool>> tmpcond;
    REP(a, r) {
      vector<bool> tmp;
      REP(b, c) tmp.push_back(cond[a][b]);
      tmpcond.push_back(tmp);
    }
    REP(k, r) {
      if (j >> k & 1) {
        REP(b, c) tmpcond[k][b] = !tmpcond[k][b];
      }
    }
    ll tmpans = 0;
    REP(b, c) {
      ll tmp = 0;
      REP(a, r) {
        if (!tmpcond[a][b])
          tmp++;
      }
      tmpans += max(tmp, r - tmp);
    }
    ans = max(ans, tmpans);
  }
  cout << ans << endl;
  return 0;
}
