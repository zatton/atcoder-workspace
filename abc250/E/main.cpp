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
template <typename T1, typename T2> void view(const vector<pair<T1, T2>> &v) {
  for (const auto &e : v) {
    cout << '(' << e.F << ',' << e.S << ')' << " ";
  }
  cout << endl;
}
template <typename T> void view(const vector<T> &v) {
  for (const auto &e : v) {
    cout << e << " ";
  }
  cout << endl;
}
template <typename T> void view(const set<T> &v) {
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

  vector<ll> a(n);
  vector<ll> b(n);

  REP(i, n)
  cin >> a[i];
  REP(i, n)
  cin >> b[i];

  set<ll> aset;
  set<ll> bset;
  set<ll> abset;

  vector<pair<ll, ll>> bext;

  ll right = 0;
  ll left = 0;

  REP(i, n) {
    debug(abset);
    debug(aset);
    debug(bset);
    if (abset.find(a[i]) != abset.end()) {
      bext.push_back(*(bext.end() - 1));
      continue;
    }
    if (bset.find(a[i]) != bset.end()) {
      bset.erase(a[i]);
      abset.insert(a[i]);
    } else
      aset.insert(a[i]);
    while (right < n && bset.size() == 0 && aset.size() > 0) {
      if (abset.find(b[right]) != abset.end())
        continue;
      if (aset.find(b[right]) != aset.end()) {
        aset.erase(b[right]);
        abset.insert(b[right]);
      } else {
        bset.insert(b[right]);
      }
      right++;
    }
    if (aset.size())
      bext.push_back(make_pair(n, n));
    else {
      left = right - 1;
      while (right < n && abset.find(b[right]) != abset.end())
        right++;
      bext.push_back(make_pair(left, right));
    }
  }

  debug(bext);
  debug(bext[4]);

  ll q;
  ll x, y;
  cin >> q;
  REP(i, q) {
    cin >> x >> y;
    x--;
    y--;
    if (bext[x].F <= y && y < bext[x].S)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
