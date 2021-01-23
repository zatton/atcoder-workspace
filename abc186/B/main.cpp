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

void solve(long long H, long long W, std::vector<std::vector<long long>> A) {
  ll min_cnt = INF64;
  ll ans = 0;
  FORA(i, A) min_cnt = min(min_cnt, *min_element(ALL(i)));
  // cout << min_cnt << endl;
  FORA(a, A) FORA(b, a) ans += b - min_cnt;
  cout << ans << endl;
}

signed main() {
  //小数の桁数の出力指定
  cout << fixed << setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long H;
  scanf("%lld", &H);
  long long W;
  scanf("%lld", &W);
  std::vector<std::vector<long long>> A(H, std::vector<long long>(W));
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      scanf("%lld", &A[i][j]);
    }
  }
  solve(H, W, std::move(A));
  return 0;
}
