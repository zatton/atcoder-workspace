#include <algorithm>
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

bool is_same_vec(const vector<int> &A, const vector<int> &B, ll n) {
  REP(i, n) {
    if (A[i] != B[i]) {
      return 0;
    }
  }
  return 1;
}

signed main() {
  ll n;
  cin >> n;
  vector<int> P;
  vector<int> Q;
  vector<int> ord;

  REP(i, n) {
    int tmp;
    cin >> tmp;
    P.push_back(tmp - 1);
  }

  REP(i, n) {
    int tmp;
    cin >> tmp;
    Q.push_back(tmp - 1);
  }

  REP(i, n) ord.push_back(i);

  ll now = 0;
  ll p_idx = 0;
  ll q_idx = 0;
  do {
    bool ok = 1;
    debug(ord);
    debug(is_same_vec(P, ord, n));
    if (is_same_vec(P, ord, n))
      p_idx = now;
    if (is_same_vec(Q, ord, n))
      q_idx = now;
    now++;
  } while (next_permutation(ALL(ord)));

  debug(p_idx);
  debug(q_idx);
  cout << abs(p_idx - q_idx) << endl;

  return 0;
}
