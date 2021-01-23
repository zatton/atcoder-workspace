#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;

//イテレーション
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= ll(b); i--)
#define FORA(i, I) for (auto &i : I)
// x:コンテナ
#define ALL(x) x.begin(), x.end()
#define SIZE(x) ll(x.size())
//定数
#define INF32 2147483647 // 2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 // 9.223372036854775807×10^{18}:64bit整数のinf
//#define MOD 1000000007 //問題による
//略記
#define F first
#define S second
//出力(空白区切りで昇順に)
#define coutALL(x)                                                             \
  for (auto i = x.begin(); i != --x.end(); i++)                                \
    cout << *i << " ";                                                         \
  cout << *--x.end() << endl;

// aをbで割る時の繰上げ,繰り下げ
ll myceil(ll a, ll b) { return (a + (b - 1)) / b; }
ll myfloor(ll a, ll b) { return a / b; }

void solve(long long N, std::vector<long long> A) {
  ll ans = 0;
  // FORA(a, A) a += 100000000;
  sort(ALL(A));
  ll s = accumulate(A.begin(), A.end(), 0LL);
  // ll s = 0;
  // FORA(a, A) s += a;
  for (ll i = N - 1; i >= 0; i--) {
    // cout << A[i] << endl;
    s -= A[i];
    ans += (A[i] * i - s);
    // ans -= s;
  }
  cout << ans << endl;
  // cout << s << endl;
  // REP(i, N) { ans += (A[i] * i - A[i] * (N - i - 1)); }
  // ans = 0;
  // REP(i, N) { ans += (-A[i] * (N - i - 1)); }
  // cout << ans << endl;
}

signed main() {
  //小数の桁数の出力指定
  // cout << fixed << setprecision(10);
  //入力の高速化用のコード
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    // scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
