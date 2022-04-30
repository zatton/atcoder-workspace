#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//イテレーション
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
//x:コンテナ
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())
//定数
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf
//#define MOD 1000000007 //問題による
//略記
#define F first
#define S second
//出力(空白区切りで昇順に)
#define coutALL(x) {for(auto i=x.begin();i!=--x.end();i++)cout<<(*i).second<<" ";cout<<(*--x.end()).second<<endl;}
// 切り上げ
ll iceil(ll a,ll b){return (a+(b-1))/b;}


void solve(long long H, long long N, std::vector<long long> A, std::vector<long long> B){
  vector<pair<long double, ll>> cp(N);

  cout << (long double)min(H, A[0]) / B[0] << endl;

  REP(i, N) cp[i] = make_pair((long double)(min(H, A[i])) / B[i], i);

  cout << endl;
  REP(i, N) cout << cp[i].first << ' ' << cp[i].second << endl;
  cout << endl;

  sort(ALL(cp));

  cout << endl;
  REP(i, N) cout << cp[i].first << ' ' << cp[i].second << endl;
  cout << endl;

  ll ans = 0;
  REP(i, N) {
    auto tmp = (*--cp.end()).S;
    cout << cp[0].first << ' ' << tmp << endl;
    ll cnt = max(1LL, H / A[tmp]);
    ans += cnt * B[tmp];
    H -= A[tmp] * cnt;
    if(H <= 0) break;
    REP(i, N) cp[i] = make_pair((long double)min(H, A[i]) / B[i], i);
    sort(ALL(cp));
  }
  cout << ans << endl;
}

signed main(){
  //小数の桁数の出力指定
  //cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long H;
  scanf("%lld",&H);
  long long N;
  scanf("%lld",&N);
  std::vector<long long> A(N);
  std::vector<long long> B(N);
  for(ll i = 0 ; i < N ; i++){
    scanf("%lld",&A[i]);
    scanf("%lld",&B[i]);
  }
  solve(H, N, std::move(A), std::move(B));
  return 0;
}
