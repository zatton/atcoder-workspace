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
#define coutALL(x) {for(auto i=x.begin();i!=--x.end();i++)cout<<*i<<" ";cout<<*--x.end()<<endl;}


void solve(long long X, long long Y, long long A, long long B, long long C, std::vector<long long> p, std::vector<long long> q, std::vector<long long> r){

}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long X;
  scanf("%lld",&X);
  long long Y;
  scanf("%lld",&Y);
  long long A;
  scanf("%lld",&A);
  long long B;
  scanf("%lld",&B);
  long long C;
  scanf("%lld",&C);
  std::vector<long long> p(A);
  for(ll i = 0 ; i < A ; i++){
    scanf("%lld",&p[i]);
  }
  std::vector<long long> q(B);
  for(ll i = 0 ; i < B ; i++){
    scanf("%lld",&q[i]);
  }
  std::vector<long long> r(C);
  for(ll i = 0 ; i < C ; i++){
    scanf("%lld",&r[i]);
  }
  solve(X, Y, A, B, C, std::move(p), std::move(q), std::move(r));
  return 0;
}
