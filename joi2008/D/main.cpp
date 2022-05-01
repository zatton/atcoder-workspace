#include <bits/stdc++.h>
#include <map>
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

struct hash_pair {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    if (hash1 != hash2)
      return hash1 ^ hash2;
    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};

signed main() {
  ll m;
  cin >> m;
  vector<pair<ll, ll>> sign;
  unordered_map<pair<ll, ll>, int, hash_pair> stars;
  // map<pair<ll, ll>, ll> stars;

  ll max_x = 0;
  ll max_y = 0;
  ll min_x = 1000001;
  ll min_y = 1000001;
  ll max_sign_x = 0;
  ll max_sign_y = 0;
  ll min_sign_x = 1000001;
  ll min_sign_y = 1000001;

  ll x1, y1;
  cin >> x1 >> y1;
  sign.push_back(make_pair(x1, y1));

  REP(i, m - 1) {
    ll x, y;
    cin >> x >> y;
    sign.push_back(make_pair(x, y));
    max_sign_x = max(max_sign_x, x);
    max_sign_y = max(max_sign_y, y);
    min_sign_x = min(min_sign_x, x);
    min_sign_y = min(min_sign_y, y);
  }

  ll n;
  cin >> n;
  REP(i, n) {
    ll x, y;
    cin >> x >> y;
    stars[make_pair(x, y)] = 1;
    max_x = max(max_x, x);
    max_y = max(max_y, y);
    min_x = min(min_x, x);
    min_y = min(min_y, y);
  }

  // cout << min_sign_x << ' ' << max_sign_x << endl;
  // cout << min_sign_y << ' ' << max_sign_y << endl;

  // cout << min_x << ' ' << max_x << endl;
  // cout << min_y << ' ' << max_y << endl << endl;

  for (auto s = stars.begin(); s != stars.end(); s++) {
    // first star of signs
    // cout << s->first.first << ' ' << s->first.second << endl;
    ll diff_x = s->first.first - x1;
    ll diff_y = s->first.second - y1;
    // cout << diff_x << ' ' << diff_y << endl;
    if (min_sign_x + diff_x < min_x || min_sign_y + diff_y < min_y ||
        max_sign_x + diff_x > max_x || max_sign_y + diff_y > max_y) {
      continue;
    }
    bool ok = 1;
    REP(i, m) {
      ll x = sign[i].first;
      ll y = sign[i].second;
      if (stars.find(make_pair(x + diff_x, y + diff_y)) != stars.end()) {
        continue;
      } else {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cout << diff_x << ' ' << diff_y << endl;
      return 0;
    }
    // cout << endl;
  }
  return 0;
}
