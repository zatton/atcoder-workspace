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
#define coutALL(x) {for(auto q=x.begin();q!=--x.end();q++)cout<<*q<<endl;cout<<*--x.end()<<endl;}

const long long MOD = 998244353;

void solve(long long N, std::vector<long long> A){
  vector<vector<ll>> dp(N, vector<ll>(10, 0));
  dp[0][A[0]] = 1;
  FOR(i, 1, N - 1) REP(j, 10) {
    //cout << i << ' ' << j << endl;

    ll tmp = (A[i] + j) % 10;
    //cout << tmp << endl;
    dp[i][tmp] = (dp[i][tmp] + dp[i - 1][j]) % MOD;

    tmp = (A[i] * j) % 10;
    //cout << tmp << endl;
    dp[i][tmp] = (dp[i][tmp] + dp[i - 1][j]) % MOD;

    //coutALL(dp[i]);
  }
  coutALL(dp[N - 1]);
  return;
}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long N;
  scanf("%lld",&N);
  std::vector<long long> A(N);
  for(ll i = 0 ; i < N ; i++){
    scanf("%lld",&A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
