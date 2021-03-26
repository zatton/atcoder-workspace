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
#define coutALL(x) for(auto i=x.begin();i!=--x.end();i++)cout<<*i<<" ";cout<<*--x.end()<<endl;

// 切り上げ
ll iceil(ll a,ll b){return (a+(b-1))/b;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


void solve(ll N, ll M, vector<ll> A) {
  sort(ALL(A));

  ll stamp = INF64;
  ll ans = 0;

  FOR(i, 1, M + 1) if(A[i - 1] + 1 != A[i]) chmin(stamp, A[i] - A[i - 1] - 1);

  if (stamp == INF64) {
    cout << 0 << endl;
    return;
  }

  FOR(i, 1, M + 1) if(A[i - 1] + 1 != A[i]) ans += iceil(A[i] - A[i - 1] - 1, stamp);
  cout << ans << endl;
}


signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M;
  cin >> N >> M;
  vector<ll> A(M + 2);
  A[0] = 0;
  REP(i, M) cin >> A[i + 1];
  A[M + 1] = N + 1;

  solve(N, M, move(A));

  return 0;
}
