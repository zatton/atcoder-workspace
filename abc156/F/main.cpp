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

const long long MOD = 2;

void solve(long long k, long long q, std::vector<long long> d, std::vector<long long> n, std::vector<long long> x, std::vector<long long> m){

}

signed main(){
  //小数の桁数の出力指定
  cout<<fixed<<setprecision(10);
  //入力の高速化用のコード
  ios::sync_with_stdio(false); // stringの時はコメントアウト
  cin.tie(nullptr);

  long long k;
  scanf("%lld",&k);
  long long q;
  scanf("%lld",&q);
  std::vector<long long> d(k-1-0+1);
  for(ll i = 0 ; i < k-1-0+1 ; i++){
    scanf("%lld",&d[i]);
  }
  std::vector<long long> n(q);
  std::vector<long long> x(q);
  std::vector<long long> m(q);
  for(ll i = 0 ; i < q ; i++){
    scanf("%lld",&n[i]);
    scanf("%lld",&x[i]);
    scanf("%lld",&m[i]);
  }
  solve(k, q, std::move(d), std::move(n), std::move(x), std::move(m));
  return 0;
}
